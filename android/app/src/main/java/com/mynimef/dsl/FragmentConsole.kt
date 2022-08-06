package com.mynimef.dsl

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.fragment.app.activityViewModels
import com.mynimef.dsl.databinding.FragmentConsoleBinding

class FragmentConsole: Fragment() {

    private val viewModel: DSLViewModel by activityViewModels()

    private var _binding: FragmentConsoleBinding? = null
    private val binding get() = _binding!!

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        _binding = FragmentConsoleBinding.inflate(inflater, container, false)
        return binding.root
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        viewModel.getOutput().observe(viewLifecycleOwner) { output ->
            binding.textOutput.text = output
        }
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}