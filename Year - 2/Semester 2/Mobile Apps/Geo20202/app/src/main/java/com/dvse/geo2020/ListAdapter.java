package com.dvse.geo2020;

import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public abstract class ListAdapter<T, VH extends RecyclerView.ViewHolder> extends RecyclerView.Adapter<VH> {

    List<T> items;

    protected Action<T> onItemSelected;

    public void setOnItemSelected(Action<T> onItemSelected) {
        this.onItemSelected = onItemSelected;
    }

    public void setItems(List<T> items) {
        this.items = items;
        notifyDataSetChanged();
    }

    public T getItem(int position) {
        if (items != null) {
            return items.get(position);
        }
        return null;
    }

    @NonNull
    @Override
    public VH onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = onCreateView(parent, viewType);
        view.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (onItemSelected != null) {
                    onItemSelected.perform((T) v.getTag(R.id.item));
                }
            }
        });
        return createViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull VH holder, int position) {
        T item = getItem(position);
        onSetupView(holder, position, item);
        holder.itemView.setTag(R.id.item, item);
    }

    protected abstract VH createViewHolder(View view);

    protected abstract View onCreateView(@NonNull ViewGroup parent, int viewType);

    protected abstract void onSetupView(@NonNull VH holder, int position, T item);

    @Override
    public int getItemCount() {
        if (items != null) {
            return items.size();
        }
        return 0;
    }
}
