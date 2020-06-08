package com.dvse.geo2020.game;

import android.content.DialogInterface;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import com.dvse.geo2020.Action;
import com.dvse.geo2020.R;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.TimeZone;

public class GameActivity extends AppCompatActivity {

    public static final String SETTINGS_KEY = "settings";

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.game_activity);

        region = findViewById(R.id.region);
        country = findViewById(R.id.country);

        answers = new ArrayList<>();
        for (int id : new int[]{R.id.answer1, R.id.answer2, R.id.answer3, R.id.answer4}){
            Button button = findViewById(id);
            button.setOnClickListener(onButtonClickListener);
            answers.add(button);
        }

        game = new Game((GameSettings) getIntent().getSerializableExtra(SETTINGS_KEY));
        game.setOnNewGameRound(new Action<GameRound>() {
            @Override
            public void perform(GameRound args) {
                showRound(args);
            }
        });
        game.setOnGameOver(new Action<GameResult>() {
            @Override
            public void perform(GameResult args) {
                showResult(args);
            }
        });
        game.startGame();
    }

    TextView region;
    TextView country;
    List<Button> answers;
    Game game;

    View.OnClickListener onButtonClickListener = new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            game.provideAnswer((String) ((Button)v).getText());
        }
    };

    void showRound(GameRound round) {
        country.setText(round.question);
        for (int i = 0 ; i < answers.size() ; ++i) {
            answers.get(i).setText(round.answers.get(i));
        }
        Toast.makeText(this, round.correctAnswer, Toast.LENGTH_SHORT).show();
    }

    void showResult(GameResult result) {
        View view = LayoutInflater.from(this).inflate(R.layout.game_result, null, false);
        ((TextView)view.findViewById(R.id.wins)).setText((String.valueOf(result.wins)));
        ((TextView)view.findViewById(R.id.date)).setText(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date(result.startTime)));
        DateFormat dateFormat = new SimpleDateFormat("HH:mm:ss");
        dateFormat.setTimeZone(TimeZone.getTimeZone("UTC"));
        ((TextView)view.findViewById(R.id.duration)).setText(dateFormat.format(new Date(result.duration)));
        new AlertDialog.Builder(this)
                .setView(view)
                .setOnCancelListener(new DialogInterface.OnCancelListener() {
                    @Override
                    public void onCancel(DialogInterface dialog) {
                        finish();
                    }
                })
                .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        finish();
                    }
                })
                .show();
    }
}
