package com.dvse.geo2020.study;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.ahmadrosid.svgloader.SvgLoader;
import com.dvse.geo2020.Action;
import com.dvse.geo2020.ListAdapter;
import com.dvse.geo2020.R;
import com.dvse.geo2020.repository.Country;

import java.util.List;

public class CountriesAdapter extends ListAdapter<Country, CountriesAdapter.ViewHolder> {

    @Override
    protected ViewHolder createViewHolder(View view) {
        return new ViewHolder(view);
    }

    @Override
    protected View onCreateView(@NonNull ViewGroup parent, int viewType) {
        return LayoutInflater.from(parent.getContext()).inflate(R.layout.countries_item, parent, false);
    }

    @Override
    protected void onSetupView(@NonNull ViewHolder holder, int position, Country item) {
        holder.name.setText(item.name);
        holder.code.setText(item.alpha2Code);
        SvgLoader.pluck().with((Activity) holder.itemView.getContext()).load(item.flag, holder.flag);
    }

    static class ViewHolder extends RecyclerView.ViewHolder {


        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            name = itemView.findViewById(R.id.name);
            code = itemView.findViewById(R.id.code);
        }

        TextView name;
        TextView code;
        ImageView flag = itemView.findViewById(R.id.flag);
    }
}
