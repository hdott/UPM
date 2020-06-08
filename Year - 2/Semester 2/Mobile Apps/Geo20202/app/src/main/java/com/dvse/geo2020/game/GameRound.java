package com.dvse.geo2020.game;

import java.util.List;

public class GameRound {

    public String question;
    List<String> answers;
    public String correctAnswer;

    public boolean provideAnswer(String value) {
        return correctAnswer.equals(value);
    }
}
