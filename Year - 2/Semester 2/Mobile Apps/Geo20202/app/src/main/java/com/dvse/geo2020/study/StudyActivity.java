package com.dvse.geo2020.study;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.dvse.geo2020.Action;
import com.dvse.geo2020.Helper;
import com.dvse.geo2020.R;

public class StudyActivity extends AppCompatActivity {

    private static final String TAG = "StudyActivity";
    
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.study_activity);

        showContinents();
    }

    void showContinents() {
        RecyclerView recyclerView = findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false));
        ContinentAdapter adapter = new ContinentAdapter();
        adapter.setItems(Helper.getContinents());
        adapter.setOnItemSelected(new Action<String>() {
            @Override
            public void perform(String args) {
                Intent intent = new Intent(StudyActivity.this, CountriesActivity.class);
                intent.putExtra(CountriesActivity.CONTINENT_KEY, args);
                startActivity(intent);
            }
        });
        recyclerView.setAdapter(adapter);
    }
}
