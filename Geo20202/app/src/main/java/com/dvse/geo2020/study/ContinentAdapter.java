package com.dvse.geo2020.study;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.dvse.geo2020.Action;
import com.dvse.geo2020.R;

import java.util.List;

public class ContinentAdapter extends RecyclerView.Adapter<ContinentAdapter.MyViewHolder> {

    public ContinentAdapter(List<String> continents, Action<String> onContinentSelected) {
        this.continents = continents;
        this.onContinentSelected = onContinentSelected;
    }

    List<String> continents;
    Action<String> onContinentSelected;

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.continents_item, parent, false);
        view.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onContinentSelected.perform((String) v.getTag(R.id.item));
            }
        });
        return new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        String continent = continents.get(position);
        holder.itemView.setTag(R.id.item, continent);
        holder.text.setText(continent);
    }

    @Override
    public int getItemCount() {
        return continents.size();
    }

    static class MyViewHolder extends RecyclerView.ViewHolder {

        public MyViewHolder(@NonNull View itemView) {
            super(itemView);
            text = itemView.findViewById(R.id.text);
        }

        TextView text;
    }
}
