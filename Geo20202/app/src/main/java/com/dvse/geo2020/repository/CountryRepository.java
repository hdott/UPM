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


public class CountryRepository {

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
                    InputStream stream = download("https://restcountries.eu/rest/v2/region" + region + "?fields=name;capital;alpha2Code;");
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
}
