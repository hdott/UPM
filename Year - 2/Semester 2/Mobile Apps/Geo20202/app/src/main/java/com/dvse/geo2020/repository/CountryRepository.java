package com.dvse.geo2020.repository;

import android.annotation.SuppressLint;
import android.os.AsyncTask;
import android.util.Log;

import com.dvse.geo2020.Action;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.List;


public class    CountryRepository {

    private static final String TAG = "CountryRepository";
    
    InputStream download(String url) throws IOException {
        HttpURLConnection connection = (HttpURLConnection) new URL(url).openConnection();
        return connection.getInputStream();
    }

    @SuppressLint("StaticFieldLeak")
    public void getCountries(final String region, final Action<List<Country>> callback) {
        new AsyncTask<Void, Void, List<Country>>() {
            @Override
            protected List<Country> doInBackground(Void... voids) {
                try {
                    Log.e(TAG, "doInBackground: ");
                    InputStream stream = download("https://restcountries.eu/rest/v2/region/" + region + "?fields=name;capital;alpha2Code;flag;");
                    return Json.getList(stream, null, Country.class);

                } catch (IOException e) {

                    Log.e(TAG, "exceptie: ");
                    e.printStackTrace();
                    return null;
                }
            }

            @Override
            protected void onPostExecute(List<Country> countries) {
                Log.e(TAG, "onPostExecute: ");
                callback.perform(countries);
            }
        }.execute();
    }

    @SuppressLint("StaticFieldLeak")
    public void getCountryDetails(final String countryCode, final Action<CountryDetails> callback) {
        new AsyncTask<Void, Void, CountryDetails>() {
            @Override
            protected CountryDetails doInBackground(Void... voids) {
                try {
                    InputStream stream = download("https://restcountries.eu/rest/v2/alpha/" + countryCode + "?fields=name;capital;alpha2Code;flag;area;population;borders;timezones");
                    return Json.getItem(stream, null, CountryDetails.class);
                } catch (IOException e) {
                    e.printStackTrace();
                    return null;
                }
            }

            @Override
            protected void onPostExecute(CountryDetails countryDetails) {
                callback.perform(countryDetails);
            }
        }.execute();
    }
}
