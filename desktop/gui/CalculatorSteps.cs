using System;
using TechTalk.SpecFlow;
using TestStack.White;
using TestStack.White.Factory;
using TestStack.White.InputDevices;
using TestStack.White.UIItems;
using TestStack.White.UIItems.WindowItems;

namespace Calc.Spec
{
    [Binding]
    public class CalculatorSteps
    {
        private Window window;

        [Before]
        public void Before()
        {
            Application application = Application.Launch("calc.exe");
            window = application.GetWindow("Calculator", InitializeOption.NoCache);
        }

        [When(@"I multiply (.*) and (.*)")]
        public void WhenIMultiply(string a, string b)
        {
            window.Keyboard.Enter(a + "*" + b + "=");
        }

        [Then(@"I should get (.*)")]
        public void ThenIShouldGet(string expected)
        {
            window.Get<Label>(expected);
        }
    }
}
