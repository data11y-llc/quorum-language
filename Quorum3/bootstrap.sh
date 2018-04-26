#!/bin/sh
#This script builds the Quorum 3.0 compiler from source.


#First create a new folder called Quorum3Compiler
mkdir Quorum3Compiler

echo "Copying Quorum compiler."
cp -r Run/ Quorum3Compiler

echo "Copying Latest Libraries."
cp -r Library Quorum3Compiler

echo "Copying Latest SourceCode"
cp -r SourceCode/ Quorum3Compiler
cd Quorum3Compiler

echo "Compiling Quorum Next in Quorum"
java -jar Default.jar -name Quorum -compile main.quorum Library.quorum CompilerRequest.quorum BitwiseTester.quorum FilesTester.quorum AddReturnTypeHint.quorum UseHint.quorum DocumentationContext.quorum CodeCompletionItem.quorum CodeCompletionRequest.quorum CodeCompletionResult.quorum ProjectInformation.quorum CompilerResult.quorum TypeCheckTesterGenerated.quorum GenericResolution.quorum TemplatingTesterGenerated.quorum ChainingTester.quorum AccessModifierContext.quorum ErrorBlockLabels.quorum ObjectAssignmentContext.quorum Action.quorum ExceptionTester.quorum ObjectToPrimitiveBooleanCast.quorum ActionCall.quorum ExplicitCastOpcode.quorum ObjectToPrimitiveIntegerCast.quorum ActionCallContext.quorum ExpressionsTester.quorum ObjectToPrimitiveNumberCast.quorum ActionCallOpcode.quorum FlipBooleanOpcode.quorum ObjectToPrimitiveTextCast.quorum ActionCallResolution.quorum FormalParameterContext.quorum Operation.quorum ActionContext.quorum FullClassDeclarationContext.quorum OutputContext.quorum ActionExpressionListContext.quorum GenericContext.quorum OutputOpcode.quorum ActionOpcode.quorum GenericDeclarationContext.quorum PackageContext.quorum ActionsNoClassContext.quorum HashListIterator.quorum ParentAssignmentContext.quorum ActionsTester.quorum HashTableTester.quorum ParentCallContext.quorum AdditionContext.quorum Hint.quorum ParentFieldAccessContext.quorum AlertContext.quorum ParentVariableFunctionCallContext.quorum AlertOpcode.quorum IfContext.quorum ParenthesisContext.quorum AlwaysBlockResource.quorum IfStatementTester.quorum ParseContext.quorum AlwaysStatementContext.quorum InequalityContext.quorum Parser.quorum AndOrContext.quorum InferenceResult.quorum QualifiedName.quorum ArrayTester.quorum InheritStatementContext.quorum QualifiedNameContext.quorum AssignmentDeclaractionContext.quorum InheritStatementsContext.quorum QueueTester.quorum AssignmentOpcode.quorum InheritanceTester.quorum QuorumBytecodeConverter.quorum AutoBoxReverseOpcode.quorum InputContext.quorum QuorumBytecodeListener.quorum BinaryAndOrOpcode.quorum InputOpcode.quorum QuorumConstant.quorum BinaryOpcode.quorum IntegerContext.quorum QuorumJavascriptListener.quorum BlankOpcode.quorum IntegerObjectToIntegerPrimitiveCast.quorum QuorumOpcode.quorum Block.quorum IntegerPrimitiveToIntegerObjectCast.quorum QuorumSourceListener.quorum BlockContext.quorum IntegerPrimitiveToNumberObjectCast.quorum RandomTester.quorum BlockOpcode.quorum IntegerPrimitiveToObjectCast.quorum ReturnContext.quorum BooleanContext.quorum IntegerToBooleanCast.quorum ReturnOpcode.quorum BooleanObjectToBooleanPrimitiveCast.quorum IntegerToNumberCast.quorum SayContext.quorum BooleanPrimitiveToBooleanObjectCast.quorum IntegerToTextCast.quorum SayOpcode.quorum BooleanPrimitiveToObjectCast.quorum IsContext.quorum SeparatedValueTester.quorum BooleanToIntegerCast.quorum IsOpcode.quorum Source.quorum BooleanToNumberCast.quorum JarGenerator.quorum StackTester.quorum BooleanToTextCast.quorum JavaBytecodeClassWriter.quorum StartContext.quorum BooleanToTextOpcode.quorum JavaBytecodeFieldWriter.quorum StatementContext.quorum CastContext.quorum JavaBytecodeLabel.quorum Symbol.quorum CastOpcode.quorum JavaBytecodeMethodWriter.quorum SymbolTable.quorum ChainedActionCallOpcode.quorum JavaBytecodeOpcodes.quorum TableTester.quorum CheckContext.quorum ListTester.quorum TemplatingTester.quorum CheckDetectOpcode.quorum Location.quorum TextContext.quorum Class.quorum LoopContext.quorum TextObjectToTextPrimitiveCast.quorum ClassOpcode.quorum LoopOpcode.quorum TextPrimitiveToObjectCast.quorum ClassStatementsContext.quorum LoopsTester.quorum TextPrimitiveToTextObjectCast.quorum ClassTypeContext.quorum MathTester.quorum TextToBooleanCast.quorum ComparisonOpcode.quorum MeContext.quorum TextToIntegerCast.quorum Compiler.quorum MeOpcode.quorum TextToNumberCast.quorum CompilerError.quorum MeVariableAccessContext.quorum Type.quorum CompilerErrorManager.quorum MultiplicationContext.quorum CompilerErrorType.quorum NegateUnaryOpcode.quorum TypeCheckResult.quorum CompilerProfiler.quorum NoActionsNoClassContext.quorum TypeCheckTester.quorum CompilerTestResult.quorum NoClassDeclarationContext.quorum TypeChecker.quorum CompilerTestSuite.quorum NoClassStatementsContext.quorum TypeConversionConstants.quorum ConcatenateOpcode.quorum NoTypeAssignmentContext.quorum TypeConversionPoints.quorum ConditionalOpcode.quorum NormalAssignmentContext.quorum UnaryMinusContext.quorum ConstructorContext.quorum NotContext.quorum UnaryOpcode.quorum CreateObjectOpcode.quorum NumberContext.quorum UndefinedContext.quorum DecompresserTester.quorum NumberObjectToNumberPrimitiveCast.quorum UseContext.quorum Dependency.quorum NumberPrimitiveToNumberObjectCast.quorum UsePackageTester.quorum DetectBlockOpcode.quorum NumberPrimitiveToObjectCast.quorum Variable.quorum DetectStatementContext.quorum NumberToBooleanCast.quorum VariableFunctionCallContext.quorum Documentation.quorum NumberToIntegerCast.quorum EqualsContext.quorum NumberToTextCast.quorum

echo "Copying Quorum Next"
cp -R ./Run/ ./


echo "Recompiling Quorum Next in Quorum Next"
rm -r Run
rm -r Build
java -jar Quorum.jar -name Quorum -compile main.quorum Library.quorum CompilerRequest.quorum BitwiseTester.quorum FilesTester.quorum AddReturnTypeHint.quorum UseHint.quorum DocumentationContext.quorum CodeCompletionItem.quorum CodeCompletionRequest.quorum CodeCompletionResult.quorum ProjectInformation.quorum CompilerResult.quorum TypeCheckTesterGenerated.quorum GenericResolution.quorum TemplatingTesterGenerated.quorum ChainingTester.quorum AccessModifierContext.quorum ErrorBlockLabels.quorum ObjectAssignmentContext.quorum Action.quorum ExceptionTester.quorum ObjectToPrimitiveBooleanCast.quorum ActionCall.quorum ExplicitCastOpcode.quorum ObjectToPrimitiveIntegerCast.quorum ActionCallContext.quorum ExpressionsTester.quorum ObjectToPrimitiveNumberCast.quorum ActionCallOpcode.quorum FlipBooleanOpcode.quorum ObjectToPrimitiveTextCast.quorum ActionCallResolution.quorum FormalParameterContext.quorum Operation.quorum ActionContext.quorum FullClassDeclarationContext.quorum OutputContext.quorum ActionExpressionListContext.quorum GenericContext.quorum OutputOpcode.quorum ActionOpcode.quorum GenericDeclarationContext.quorum PackageContext.quorum ActionsNoClassContext.quorum HashListIterator.quorum ParentAssignmentContext.quorum ActionsTester.quorum HashTableTester.quorum ParentCallContext.quorum AdditionContext.quorum Hint.quorum ParentFieldAccessContext.quorum AlertContext.quorum ParentVariableFunctionCallContext.quorum AlertOpcode.quorum IfContext.quorum ParenthesisContext.quorum AlwaysBlockResource.quorum IfStatementTester.quorum ParseContext.quorum AlwaysStatementContext.quorum InequalityContext.quorum Parser.quorum AndOrContext.quorum InferenceResult.quorum QualifiedName.quorum ArrayTester.quorum InheritStatementContext.quorum QualifiedNameContext.quorum AssignmentDeclaractionContext.quorum InheritStatementsContext.quorum QueueTester.quorum AssignmentOpcode.quorum InheritanceTester.quorum QuorumBytecodeConverter.quorum AutoBoxReverseOpcode.quorum InputContext.quorum QuorumBytecodeListener.quorum BinaryAndOrOpcode.quorum InputOpcode.quorum QuorumConstant.quorum BinaryOpcode.quorum IntegerContext.quorum QuorumJavascriptListener.quorum BlankOpcode.quorum IntegerObjectToIntegerPrimitiveCast.quorum QuorumOpcode.quorum Block.quorum IntegerPrimitiveToIntegerObjectCast.quorum QuorumSourceListener.quorum BlockContext.quorum IntegerPrimitiveToNumberObjectCast.quorum RandomTester.quorum BlockOpcode.quorum IntegerPrimitiveToObjectCast.quorum ReturnContext.quorum BooleanContext.quorum IntegerToBooleanCast.quorum ReturnOpcode.quorum BooleanObjectToBooleanPrimitiveCast.quorum IntegerToNumberCast.quorum SayContext.quorum BooleanPrimitiveToBooleanObjectCast.quorum IntegerToTextCast.quorum SayOpcode.quorum BooleanPrimitiveToObjectCast.quorum IsContext.quorum SeparatedValueTester.quorum BooleanToIntegerCast.quorum IsOpcode.quorum Source.quorum BooleanToNumberCast.quorum JarGenerator.quorum StackTester.quorum BooleanToTextCast.quorum JavaBytecodeClassWriter.quorum StartContext.quorum BooleanToTextOpcode.quorum JavaBytecodeFieldWriter.quorum StatementContext.quorum CastContext.quorum JavaBytecodeLabel.quorum Symbol.quorum CastOpcode.quorum JavaBytecodeMethodWriter.quorum SymbolTable.quorum ChainedActionCallOpcode.quorum JavaBytecodeOpcodes.quorum TableTester.quorum CheckContext.quorum ListTester.quorum TemplatingTester.quorum CheckDetectOpcode.quorum Location.quorum TextContext.quorum Class.quorum LoopContext.quorum TextObjectToTextPrimitiveCast.quorum ClassOpcode.quorum LoopOpcode.quorum TextPrimitiveToObjectCast.quorum ClassStatementsContext.quorum LoopsTester.quorum TextPrimitiveToTextObjectCast.quorum ClassTypeContext.quorum MathTester.quorum TextToBooleanCast.quorum ComparisonOpcode.quorum MeContext.quorum TextToIntegerCast.quorum Compiler.quorum MeOpcode.quorum TextToNumberCast.quorum CompilerError.quorum MeVariableAccessContext.quorum Type.quorum CompilerErrorManager.quorum MultiplicationContext.quorum CompilerErrorType.quorum NegateUnaryOpcode.quorum TypeCheckResult.quorum CompilerProfiler.quorum NoActionsNoClassContext.quorum TypeCheckTester.quorum CompilerTestResult.quorum NoClassDeclarationContext.quorum TypeChecker.quorum CompilerTestSuite.quorum NoClassStatementsContext.quorum TypeConversionConstants.quorum ConcatenateOpcode.quorum NoTypeAssignmentContext.quorum TypeConversionPoints.quorum ConditionalOpcode.quorum NormalAssignmentContext.quorum UnaryMinusContext.quorum ConstructorContext.quorum NotContext.quorum UnaryOpcode.quorum CreateObjectOpcode.quorum NumberContext.quorum UndefinedContext.quorum DecompresserTester.quorum NumberObjectToNumberPrimitiveCast.quorum UseContext.quorum Dependency.quorum NumberPrimitiveToNumberObjectCast.quorum UsePackageTester.quorum DetectBlockOpcode.quorum NumberPrimitiveToObjectCast.quorum Variable.quorum DetectStatementContext.quorum NumberToBooleanCast.quorum VariableFunctionCallContext.quorum Documentation.quorum NumberToIntegerCast.quorum EqualsContext.quorum NumberToTextCast.quorum

echo "Copying to NetBeans Installation"
#rm ../../IDE/Sodbeans/Quorum/release/modules/ext/Quorum.jar
cp Run/Quorum.jar ../../IDE/Sodbeans/Quorum/release/modules/ext/Quorum.jar

#chmod -R +rw ../../IDE/Sodbeans/Quorum/release/modules/Library/Standard/Libraries/

#By default, get rid of the library package and put it back in.
rm -r ../../IDE/Sodbeans/Quorum/release/modules/Library
cp -r Library ../../IDE/Sodbeans/Quorum/release/modules


#Make the folder and all of its contents read only
#chmod -R-w ../../IDE/Sodbeans/Quorum/release/modules/Library/Standard/Libraries/

echo "Copying Quorum to its final form."
mkdir ../Quorum
cp Run/Quorum.jar ../Quorum/Quorum.jar

cp -r Library ../Quorum/Library

echo "Running test suite"
#java -jar Quorum.jar -test

echo "Cleaning up Temporary Folders"
cd ..


rm -r Quorum3Compiler
#If we don't want to store the final version, delete it.
rm -r Quorum
echo "Finished."