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

    val consoleOutput = MutableLiveData("")

    fun run(code: String) {
        consoleOutput.postValue("")
        Thread {
            execute(code)
        }.start()
    }

    fun addToOutput(output: String) {
        consoleOutput.postValue(consoleOutput.value + output)
    }
}