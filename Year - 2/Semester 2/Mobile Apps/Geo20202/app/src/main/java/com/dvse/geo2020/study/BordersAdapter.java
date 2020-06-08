package com.dvse.geo2020.study;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.dvse.geo2020.ListAdapter;
import com.dvse.geo2020.R;

public class BordersAdapter extends ListAdapter<String, BordersAdapter.ViewHolder> {

    @Override
    protected ViewHolder createViewHolder(View view) {
        return new ViewHolder(view);
    }

    @Override
    protected View onCreateView(@NonNull ViewGroup parent, int viewType) {
        return LayoutInflater.from(parent.getContext()).inflate(R.layout.borders_item, parent, false);
    }

    @Override
    protected void onSetupView(@NonNull ViewHolder holder, int position, String item) {
        holder.text.setText(item);
    }

    static class ViewHolder extends RecyclerView.ViewHolder {

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            text = itemView.findViewById(R.id.text);
        }
        TextView text;
    }
}
