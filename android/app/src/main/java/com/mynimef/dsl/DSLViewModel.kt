package com.mynimef.dsl

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel

class DSLViewModel: ViewModel() {

    private external fun execute(code: String)

    companion object {
        init {
            System.loadLibrary("dsl")
        }
    }

    val consoleOutput = MutableLiveData<String>()

    fun run(code: String) {
        Thread {
            execute(code)
            println("end")
        }.start()
    }

    fun addToOutput(output: String) {

        println("start")
        consoleOutput.postValue(consoleOutput.value + output)
    }
}