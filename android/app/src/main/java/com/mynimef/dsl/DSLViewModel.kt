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
            execute(code.replace(" ", " "))
        }.start()
    }

    fun addToOutput(output: String) {
        consoleOutput.postValue(consoleOutput.value + output)
    }

    private val codeHighlights = mapOf(
        "\\b((while)|(if)|(else)|(true)|(false))\\b".toRegex() to "#CC7832", //ORANGE
        "\\b((0|([1-9][0-9]*))\\.*[0-9]*)\\b".toRegex()        to "#6887BB", //BLUE
        "\"[^\"]*\"".toRegex()                                 to "#6A8759", //GREEN
        "\\b(func)\\b".toRegex()                               to "#FFC66D", //YELLOW
    )

    fun highlightText(text: CharSequence): String {
        var modifiedString = text
            .replace("\n".toRegex(), "<br/>")
            .replace(" ".toRegex(), "&nbsp;")
        codeHighlights.forEach { map ->
            modifiedString = modifiedString.replace(map.key) {
                "<font color='${map.value}'>${it.value}</font>"
            }
        }
        return modifiedString
    }
}