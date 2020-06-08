package com.dvse.geo2020.game;

import com.dvse.geo2020.Action;
import com.dvse.geo2020.repository.Country;
import com.dvse.geo2020.repository.CountryRepository;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class Game {

    GameSettings settings;

    List<Country> countries;
    int rounds;
    GameRound current;
    List<String> prevQuestions = new ArrayList<>();
    GameResult result = new GameResult();

    public void setOnNewGameRound(Action<GameRound> onNewGameRound) {
        this.onNewGameRound = onNewGameRound;
    }

    Action<GameRound> onNewGameRound;

    public void setOnGameOver(Action<GameResult> onGameOver) {
        this.onGameOver = onGameOver;
    }

    Action<GameResult> onGameOver;

    public Game(GameSettings settings) {
        this.settings = settings;
    }

    public void startGame() {
        new CountryRepository().getCountries(settings.region, new Action<List<Country>>() {
            @Override
            public void perform(List<Country> args) {
                countries = args;
                result.startTime = System.currentTimeMillis();
                nextRound();
            }
        });
    }

    public void provideAnswer(String answer) {
        if (current.provideAnswer(answer)) {
            result.wins++;
        }
        nextRound();
    }

    void nextRound() {
        if (settings.nrQuestions == rounds) {
            result.duration = System.currentTimeMillis() - result.startTime;
            onGameOver.perform(result);
        } else {
            rounds++;
            current = createNewRound();
            onNewGameRound.perform(current);
        }
    }

    GameRound createNewRound() {
        Random random = new Random();
        GameRound res = new GameRound();
        Country question = getRandomCountry(random, prevQuestions);
        res.question = question.name;
        res.correctAnswer = question.capital;

        res.answers = new ArrayList<>();
        List<String> prevAnswers = new ArrayList<>();
        for (int i = 0 ; i < 3 ; ++i) {
            Country country = getRandomCountry(random, prevAnswers);
            res.answers.add(country.capital);
        }
        res.answers.add(res.correctAnswer);
        Collections.shuffle(res.answers);

        return res;
    }

    Country getRandomCountry(Random random, List<String> forbidden) {
        Country res = null;
        while (res == null) {
            res = countries.get(random.nextInt(countries.size()));
            if (forbidden.contains(res.name)) {
                res = null;
            }
        }
        forbidden.add(res.name);

        return res;
    }
}
