package com.dvse.geo2020.game;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Build;
import android.widget.ArrayAdapter;
import android.widget.Spinner;

import androidx.annotation.RequiresApi;

import com.dvse.geo2020.Helper;
import com.dvse.geo2020.R;

public class GameSettingsDialog {
    @RequiresApi(api = Build.VERSION_CODES.LOLLIPOP)
    public void show(Context context) {
        Dialog dialog = new AlertDialog.Builder(context)
                .setView(R.layout.game_settings)
                .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface di, int which) {
                        Dialog dialog = (Dialog) di;
                        GameSettings settings = new GameSettings();
                        settings.region = (String) ((Spinner) dialog.findViewById(R.id.regions)).getSelectedItem();
                        settings.nrQuestions = (int) ((Spinner) dialog.findViewById(R.id.questions)).getSelectedItem();
                        Intent intent = new Intent(dialog.getContext(), GameActivity.class);
                        intent.putExtra(GameActivity.SETTINGS_KEY, settings);
                        dialog.getContext().startActivity(intent);
                    }
                })
                .show();
        Spinner questions = dialog.findViewById(R.id.questions);
        questions.setAdapter(new ArrayAdapter<>(dialog.getContext(), android.R.layout.simple_list_item_1, Helper.getNrQuestions()));

        Spinner regions = dialog.findViewById(R.id.regions);
        regions.setAdapter(new ArrayAdapter<>(dialog.getContext(), android.R.layout.simple_list_item_1, Helper.getContinents()));
    }
}
