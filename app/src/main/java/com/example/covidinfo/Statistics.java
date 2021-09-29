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
    static int affecti, recoveri, deathsi, activei,seriousi,pactivei, pdeathsi, precoveri,up;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_statistics);
        list = new ArrayList<>();
        init();
        /*ApiUtilities.getApiInterface().getCountryData().enqueue(new Callback<List<CountryData>>() {
            @Override
            public void onResponse(Call<List<CountryData>> call, Response<List<CountryData>> response) {
                list.addAll(response.body());
                for(int i=0;i<list.size();i++){
                    if(list.get(i).getCountry().equals("India")){
                         affecti = Integer.parseInt( list.get(i).getCases());
                         recoveri = Integer.parseInt( list.get(i).getRecovered());
                         deathsi = Integer.parseInt( list.get(i).getDeaths());
                         activei = Integer.parseInt(  list.get(i).getActive());
                         seriousi = Integer.parseInt(  list.get(i).getCritical());
                         pactivei = Integer.parseInt( list.get(i).getTodayCases());
                         pdeathsi = Integer.parseInt( list.get(i).getTodayDeaths());
                         precoveri = Integer.parseInt( list.get(i).getTodayRecovered());
                         up = Integer.parseInt( list.get(i).getUpdated());
                        break;
                    }
                }
            }
            @Override
            public void onFailure(Call<List<CountryData>> call, Throwable t) {
                Toast.makeText(Statistics.this, "Error" + t.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });*/
        affecti = 33716451;
        seriousi = 8944;
        recoveri = 32986180;
        precoveri =  7623;
        deathsi = 447781;
        pdeathsi = 0;
        activei= 282490;
        pactivei = 1402;
        active.setText(String.valueOf(activei));
        serious.setText(String.valueOf(seriousi));
        recover.setText(String.valueOf(recoveri));
        deaths.setText(String.valueOf(deathsi));
        affect.setText(String.valueOf(affecti));
        precover.setText("95%");
        pdeaths.setText("2%");
        pserious.setText("1%");
        pactive.setText("2%");
        Toast.makeText(Statistics.this, "new data come after 24 hours"  , Toast.LENGTH_SHORT).show();
        pieChart.addPieSlice(new PieModel("Serious" , 1, Color.parseColor("#9059ff")));
        pieChart.addPieSlice(new PieModel("Recovered" , 95 , Color.parseColor("#43d97b")));
        pieChart.addPieSlice(new PieModel("Active" , 2, Color.parseColor("#ff5959")));
        pieChart.addPieSlice(new PieModel("Deaths" , 2 , Color.parseColor("#4db5ff")));
        pieChart.startAnimation();
    }
    private void init(){
        affect = (TextView) findViewById(R.id.textView12);
        recover = (TextView) findViewById(R.id.textView18);
        deaths = (TextView) findViewById(R.id.textView14);
        active = (TextView) findViewById(R.id.textView16);
        serious = (TextView) findViewById(R.id.textView20);
        precover = (TextView) findViewById(R.id.tv514);
        pdeaths = (TextView) findViewById(R.id.tv512);
        pserious = (TextView) findViewById(R.id.tv515);
        pactive = (TextView) findViewById(R.id.tv513);
        pieChart = findViewById(R.id.piechart);
    }
}