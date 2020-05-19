package com.example.dialer;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Pair;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    private Button mOne;
    private Button mTwo;
    private Button mThree;
    private Button mFour;
    private Button mFive;
    private Button mSix;
    private Button mSeven;
    private Button mEight;
    private Button mNine;
    private Button mStar;
    private Button mZero;
    private Button mDiez;
    private Button mCall;
    private Button mDel;
    private TextView mPhone;
    private ListView mList;
    private ArrayList<String> lista;
    private ArrayAdapter<String> adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mOne = findViewById(R.id.one_button);
        mTwo = findViewById(R.id.two_button);
        mThree = findViewById(R.id.three_button);
        mFour = findViewById(R.id.four_button);
        mFive = findViewById(R.id.five_button);
        mSix = findViewById(R.id.six_button);
        mSeven = findViewById(R.id.seven_button);
        mEight = findViewById(R.id.eight_button);
        mNine = findViewById(R.id.nine_button);
        mStar = findViewById(R.id.star_button);
        mZero = findViewById(R.id.zero_button);
        mDiez = findViewById(R.id.diez_button);
        mCall = findViewById(R.id.call_button);
        mDel = findViewById(R.id.delete_button);
        mPhone = findViewById(R.id.phone_textview);
        mList = findViewById(R.id.recent_listview);


        mOne.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("1");
            }
        });

        mTwo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("2");
            }
        });

        mThree.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("3");
            }
        });

        mFour.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("4");
            }
        });

        mFive.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("5");
            }
        });

        mSix.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("6");
            }
        });

        mSeven.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("7");
            }
        });

        mEight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("8");
            }
        });

        mNine.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("9");
            }
        });

        mStar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("*");
            }
        });

        mZero.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("0");
            }
        });

        mDiez.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPhone.append("#");
            }
        });

        mDel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(mPhone.getText().length() >= 1){
                    String number = mPhone.getText().toString();
                    mPhone.setText(number.toCharArray(), 0, number.length()-1);
                }
            }
        });

//        lista = new LinkedList<>();
        lista = new ArrayList<>();
        adapter = new ArrayAdapter<String>(this, R.layout.list_item, R.id.item, lista);
//        adapter = new ArrayAdapter<String>(this, )
        mList.setAdapter(adapter);
        mCall.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(mPhone.getText().length() >= 4){
                    lista.add(mPhone.getText().toString());
                    adapter.notifyDataSetChanged();
                } else {
                    int msgId = R.string.length_warning;
                    Toast.makeText(getApplicationContext(),
                            msgId,
                            Toast.LENGTH_SHORT).show();
                }
            }
        });
    }


}
