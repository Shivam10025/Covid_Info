package com.example.covidinfo;
//new project
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

//covid details
public class MainActivity extends AppCompatActivity {
    Button b1,b2,b3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        b1=findViewById(R.id.button);
        b2=findViewById(R.id.button2);
        b3=findViewById(R.id.stat);
        b3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i=new Intent(MainActivity.this,Statistics.class);
                startActivity(i);
            }
        });
        b1.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View arg0) {
                String number="108";
                Intent callIntent = new Intent(Intent.ACTION_CALL);
                callIntent.setData(Uri.parse("tel:"+number));
                startActivity(callIntent);
            }

        });
        b2.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View arg0) {
                String number="108";
                Intent callIntent = new Intent(Intent.ACTION_CALL);
                callIntent.setData(Uri.parse("tel:"+number));
                startActivity(callIntent);
            }

        });
    }
}