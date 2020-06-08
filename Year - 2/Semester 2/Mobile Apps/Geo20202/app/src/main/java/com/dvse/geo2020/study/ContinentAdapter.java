package com.dvse.geo2020.study;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.dvse.geo2020.Action;
import com.dvse.geo2020.ListAdapter;
import com.dvse.geo2020.R;

import java.util.List;

public class ContinentAdapter extends ListAdapter<String, ContinentAdapter.MyViewHolder> {

    @Override
    protected MyViewHolder createViewHolder(View view) {
        return new MyViewHolder(view);
    }

    @Override
    protected View onCreateView(@NonNull ViewGroup parent, int viewType) {
        return LayoutInflater.from(parent.getContext()).inflate(R.layout.continents_item, parent, false);
    }

    @Override
    protected void onSetupView(@NonNull MyViewHolder holder, int position, String item) {
        holder.text.setText(item);
    }

    static class MyViewHolder extends RecyclerView.ViewHolder {

        public MyViewHolder(@NonNull View itemView) {
            super(itemView);
            text = itemView.findViewById(R.id.text);
        }

        TextView text;
    }
}
