package com.dvse.geo2020.study;

import android.os.Bundle;
import android.os.PersistableBundle;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.dvse.geo2020.Action;
import com.dvse.geo2020.R;
import com.dvse.geo2020.repository.Country;
import com.dvse.geo2020.repository.CountryRepository;

import java.util.List;

public class CountriesActivity extends AppCompatActivity {

    private static final String TAG = "CountriesActivity";
    public static String CONTINENT_KEY = "continent";

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        Log.e(TAG, "setContentView: ");
        setContentView(R.layout.recycler_view);

        continent = getIntent().getStringExtra(CONTINENT_KEY);

        Log.e(TAG, "onPostExecute: ");
        new CountryRepository().getCountries(continent, new Action<List<Country>>() {
            @Override
            public void perform(List<Country> args) {
                RecyclerView recyclerView = findViewById(R.id.recyclerView);
                recyclerView.setLayoutManager(new LinearLayoutManager(CountriesActivity.this, LinearLayoutManager.VERTICAL, false));
                recyclerView.setAdapter(new CountriesAdapter(args));
            }
        });
        Toast.makeText(this, continent, Toast.LENGTH_SHORT);
    }

//    @Override
//    public void onCreate(@Nullable Bundle savedInstanceState, @Nullable PersistableBundle persistentState) {
//        super.onCreate(savedInstanceState, persistentState);
//
//    }

    String continent;
}
