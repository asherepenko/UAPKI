package com.sit.uapki.android

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.sit.uapki.Library
import com.sit.uapki.android.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val lib = Library(true)

        // Example of a call to a native method
        binding.sampleText.text = "${lib.name}.${lib.version}"
    }

}
