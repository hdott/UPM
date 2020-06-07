package com.dvse.geo2020.study;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.dvse.geo2020.R;
import com.dvse.geo2020.repository.Country;

import java.util.List;

public class CountriesAdapter extends RecyclerView.Adapter<CountriesAdapter.ViewHolder> {

    public CountriesAdapter(List<Country> countries) {
        this.countries = countries;
    }

    List<Country> countries;

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View res = LayoutInflater.from(parent.getContext()).inflate(R.layout.countries_item, parent, false);
        return new ViewHolder(res);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        holder.text.setText(countries.get(position).name);
    }

    @Override
    public int getItemCount() {
        return 5;
    }

    static class ViewHolder extends RecyclerView.ViewHolder {


        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            text = itemView.findViewById(R.id.text);
        }

        TextView text;
    }
}
