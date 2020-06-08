package com.dvse.geo2020.study;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.ahmadrosid.svgloader.SvgLoader;
import com.dvse.geo2020.Action;
import com.dvse.geo2020.R;
import com.dvse.geo2020.repository.Country;
import com.dvse.geo2020.repository.CountryDetails;
import com.dvse.geo2020.repository.CountryRepository;

import java.text.DateFormat;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.SimpleTimeZone;
import java.util.TimeZone;

public class CountryActivity extends AppCompatActivity {

    public static final String COUNTRY_KEY = "country";

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.country_details_activity);
        showCountry((Country) getIntent().getSerializableExtra(COUNTRY_KEY));
    }

    void showCountry(Country country) {
        ((TextView)findViewById(R.id.name)).setText(String.format("%s (%s)", country.name, country.alpha2Code));
        ((TextView)findViewById(R.id.capital)).setText(country.capital);
        SvgLoader.pluck().with(this).load(country.flag, (ImageView)findViewById(R.id.flag));
        new CountryRepository().getCountryDetails(country.alpha2Code, new Action<CountryDetails>() {
            @Override
            public void perform(CountryDetails args) {
                showCountryDetails(args);
            }
        });
    }

    void showCountryDetails(CountryDetails countryDetails) {
        ((TextView)findViewById(R.id.area)).setText(String.format("%s km²", new DecimalFormat().format(countryDetails.area)));
        ((TextView)findViewById(R.id.population)).setText(new DecimalFormat().format(countryDetails.population));
        startUpdateTime(countryDetails);
        updateTime(countryDetails);
        RecyclerView recyclerView = findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false));
        BordersAdapter adapter = new BordersAdapter();
        adapter.setOnItemSelected(new Action<String>() {
            @Override
            public void perform(String args) {
                onBorderItemSelected(args);
            }
        });
        adapter.setItems(countryDetails.borders);
        recyclerView.setAdapter(adapter);
    }

    void onBorderItemSelected(String code) {
        new CountryRepository().getCountryDetails(code, new Action<CountryDetails>() {
            @Override
            public void perform(CountryDetails args) {
                Intent intent = new Intent(CountryActivity.this, CountryActivity.class);
                intent.putExtra(COUNTRY_KEY, args);
                startActivity(intent);
            }
        });
    }

    void startUpdateTime(final CountryDetails countryDetails) {
        updateTime(countryDetails);
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                startUpdateTime(countryDetails);
            }
        }, 1000);
    }

    void updateTime(CountryDetails details) {
        ((TextView)findViewById(R.id.time)).setText(convertTime(details.timezones.get(0)));
    }

    String convertTime(String timeZoneValue) {
        TimeZone timeZone = new SimpleTimeZone(getRawOffset(timeZoneValue), timeZoneValue);
        DateFormat dateFormat = new SimpleDateFormat("HH:mm:ss", Locale.getDefault());
        return String.format("%s (%s)", dateFormat.format(new Date()), timeZoneValue);
    }

    int getRawOffset(String timeZoneOffset) {
        int res = 0;
        timeZoneOffset = timeZoneOffset.substring(3);

        if (timeZoneOffset.length() == 6) {
            res += 3600 * Integer.parseInt(timeZoneOffset.substring(1,3));
            res += 60 * Integer.parseInt(timeZoneOffset.substring(4,6));
        } else if (timeZoneOffset.length() == 3) {
            res += 3600 * Integer.parseInt(timeZoneOffset.substring(1,3));
        }
        res = res * (timeZoneOffset.startsWith("-") ? -1 : 1);
        res = res * 1000;

        return res;
    }
}
