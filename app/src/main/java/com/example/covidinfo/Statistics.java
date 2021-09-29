package com.example.covidinfo;

import androidx.appcompat.app.AppCompatActivity;
import android.graphics.Color;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

import com.example.covidinfo.api.ApiUtilities;
import com.example.covidinfo.api.CountryData;

import org.eazegraph.lib.charts.PieChart;
import org.eazegraph.lib.models.PieModel;

import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class Statistics extends AppCompatActivity {
    private TextView affect , recover , deaths , active , serious;
    private TextView precover , pdeaths , pactive , pserious;
    private List<CountryData>list;
    PieChart pieChart;
    String affecti , recoveri , deathsi , activei,seriousi,pactivei, pdeathsi , precoveri , up;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_statistics);
        list = new ArrayList<>();
        init();
        ApiUtilities.getApiInterface().getCountryData().enqueue(new Callback<List<CountryData>>() {
            @Override
            public void onResponse(Call<List<CountryData>> call, Response<List<CountryData>> response) {
                list.addAll(response.body());
                for(int i=0;i<list.size();i++){
                    if(list.get(i).getCountry().equals("India")){
                         affecti = list.get(i).getCases();
                         recoveri = list.get(i).getRecovered();
                         deathsi = list.get(i).getDeaths();
                         activei = list.get(i).getActive();
                         seriousi = list.get(i).getCritical();
                         pactivei = list.get(i).getTodayCases();
                         pdeathsi = list.get(i).getTodayDeaths();
                         precoveri = list.get(i).getTodayRecovered();
                         up = list.get(i).getUpdated();
                        break;
                    }
                }
            }
            @Override
            public void onFailure(Call<List<CountryData>> call, Throwable t) {
                Toast.makeText(Statistics.this, "Error" + t.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });
        active.setText(NumberFormat.getInstance().format(Integer.parseInt(activei)));
        serious.setText(NumberFormat.getInstance().format(Integer.parseInt(seriousi)));
        recover.setText((NumberFormat.getInstance().format(Integer.parseInt(recoveri)))+" , +"+(NumberFormat.getInstance().format(Integer.parseInt(precoveri))));
        deaths.setText((NumberFormat.getInstance().format(Integer.parseInt(deathsi)))+" , +"+(NumberFormat.getInstance().format(Integer.parseInt(pdeathsi))));
        affect.setText((NumberFormat.getInstance().format(Integer.parseInt(affecti)))+" , +"+(NumberFormat.getInstance().format(Integer.parseInt(pactivei))));
        Toast.makeText(Statistics.this, "new data come after 24 hours"  , Toast.LENGTH_SHORT).show();
        pieChart.addPieSlice(new PieModel("Serious" , Integer.parseInt(seriousi) , Color.parseColor("#9059ff")));
        pieChart.addPieSlice(new PieModel("Recovered" , Integer.parseInt(recoveri) , Color.parseColor("#43d97b")));
        pieChart.addPieSlice(new PieModel("Active" , Integer.parseInt(deathsi) , Color.parseColor("#ff5959")));
        pieChart.addPieSlice(new PieModel("Serious" , Integer.parseInt(seriousi) , Color.parseColor("#4db5ff")));
        pieChart.startAnimation();
    }
    private void init(){
        affect = findViewById(R.id.textView12);
        recover = findViewById(R.id.textView18);
        deaths = findViewById(R.id.textView14);
        active = findViewById(R.id.textView16);
        serious = findViewById(R.id.textView20);
    }
}