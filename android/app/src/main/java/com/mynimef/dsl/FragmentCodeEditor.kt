package com.mynimef.dsl

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.core.text.HtmlCompat
import androidx.core.widget.doOnTextChanged
import androidx.fragment.app.Fragment
import androidx.fragment.app.activityViewModels
import androidx.fragment.app.commit
import com.mynimef.dsl.databinding.FragmentCodeEditorBinding

class FragmentCodeEditor: Fragment() {

    private val viewModel: DSLViewModel by activityViewModels()

    private var _binding: FragmentCodeEditorBinding? = null
    private val binding get() = _binding!!

    private var modifyEnabled = true

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        _binding = FragmentCodeEditorBinding.inflate(inflater, container, false)
        return binding.root
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        binding.executeButton.setOnClickListener {
            requireActivity().supportFragmentManager.commit {
                setReorderingAllowed(true)
                addToBackStack(null)
                add(R.id.containerView, FragmentConsole())
            }
            viewModel.run(binding.editCode.text.toString())
        }

        binding.editCode.doOnTextChanged { text, start, before, count ->
            if (!text.isNullOrEmpty() && modifyEnabled) {
                modifyEnabled = false
                val modifiedText = text
                    .replace("\n".toRegex(), "<br />")
                    .replace("while".toRegex(), "<font color='red'>while</font>")
                binding.editCode.setText(HtmlCompat.fromHtml(modifiedText, HtmlCompat.FROM_HTML_MODE_LEGACY))
                binding.editCode.setSelection(start + count)
            } else {
                modifyEnabled = true
            }
        }
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}