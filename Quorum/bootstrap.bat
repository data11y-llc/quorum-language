REM !/bin/sh
REM This script builds the Quorum 3.0 compiler from source.


REM First create a new folder called Quorum3Compiler
mkdir Quorum3Compiler

echo "Copying Quorum compiler."
robocopy Run/ Quorum3Compiler /s /e /NFL /NDL /NJH /NJS /nc /ns /np

echo "Copying Latest Libraries."
robocopy Library Quorum3Compiler/Library /s /e /NFL /NDL /NJH /NJS /nc /ns /np

echo "Copying Latest SourceCode"
robocopy SourceCode/ Quorum3Compiler /s /e /NFL /NDL /NJH /NJS /nc /ns /np
cd Quorum3Compiler

echo "Compiling Quorum Next in Quorum"
REM java -jar Default.jar -name Quorum -compile main.quorum NavigationBar.quorum JsonTester.quorum MatrixTester.quorum DocumentationGenerator.quorum ClassAttribute.quorum CodeCompletionHandler.quorum Library.quorum CompilerRequest.quorum BitwiseTester.quorum FilesTester.quorum AddReturnTypeHint.quorum UseHint.quorum DocumentationContext.quorum CodeCompletionItem.quorum CodeCompletionRequest.quorum CodeCompletionResult.quorum CompilerResult.quorum TypeCheckTesterGenerated.quorum GenericResolution.quorum TemplatingTesterGenerated.quorum ChainingTester.quorum AccessModifierContext.quorum ErrorBlockLabels.quorum ObjectAssignmentContext.quorum Action.quorum ExceptionTester.quorum ObjectToPrimitiveBooleanCast.quorum ActionCall.quorum ExplicitCastOpcode.quorum ObjectToPrimitiveIntegerCast.quorum ActionCallContext.quorum ExpressionsTester.quorum ObjectToPrimitiveNumberCast.quorum ActionCallOpcode.quorum FlipBooleanOpcode.quorum ObjectToPrimitiveTextCast.quorum ActionCallResolution.quorum FormalParameterContext.quorum Operation.quorum ActionContext.quorum FullClassDeclarationContext.quorum OutputContext.quorum ActionExpressionListContext.quorum GenericContext.quorum OutputOpcode.quorum ActionOpcode.quorum GenericDeclarationContext.quorum PackageContext.quorum ActionsNoClassContext.quorum HashListIterator.quorum ParentAssignmentContext.quorum ActionsTester.quorum HashTableTester.quorum ParentCallContext.quorum AdditionContext.quorum Hint.quorum ParentFieldAccessContext.quorum AlertContext.quorum ParentVariableFunctionCallContext.quorum AlertOpcode.quorum IfContext.quorum ParenthesisContext.quorum AlwaysBlockResource.quorum IfStatementTester.quorum ParseContext.quorum AlwaysStatementContext.quorum InequalityContext.quorum Parser.quorum AndOrContext.quorum InferenceResult.quorum QualifiedName.quorum ArrayTester.quorum InheritStatementContext.quorum QualifiedNameContext.quorum AssignmentDeclaractionContext.quorum InheritStatementsContext.quorum QueueTester.quorum AssignmentOpcode.quorum InheritanceTester.quorum QuorumBytecodeConverter.quorum AutoBoxReverseOpcode.quorum InputContext.quorum QuorumBytecodeListener.quorum BinaryAndOrOpcode.quorum InputOpcode.quorum QuorumConstant.quorum BinaryOpcode.quorum IntegerContext.quorum QuorumJavascriptListener.quorum BlankOpcode.quorum IntegerObjectToIntegerPrimitiveCast.quorum QuorumOpcode.quorum Block.quorum IntegerPrimitiveToIntegerObjectCast.quorum QuorumSourceListener.quorum BlockContext.quorum IntegerPrimitiveToNumberObjectCast.quorum RandomTester.quorum BlockOpcode.quorum IntegerPrimitiveToObjectCast.quorum ReturnContext.quorum BooleanContext.quorum IntegerToBooleanCast.quorum ReturnOpcode.quorum BooleanObjectToBooleanPrimitiveCast.quorum IntegerToNumberCast.quorum SayContext.quorum BooleanPrimitiveToBooleanObjectCast.quorum IntegerToTextCast.quorum SayOpcode.quorum BooleanPrimitiveToObjectCast.quorum IsContext.quorum SeparatedValueTester.quorum BooleanToIntegerCast.quorum IsOpcode.quorum Source.quorum BooleanToNumberCast.quorum JarGenerator.quorum StackTester.quorum BooleanToTextCast.quorum JavaBytecodeClassWriter.quorum StartContext.quorum BooleanToTextOpcode.quorum JavaBytecodeFieldWriter.quorum StatementContext.quorum CastContext.quorum JavaBytecodeLabel.quorum Symbol.quorum CastOpcode.quorum JavaBytecodeMethodWriter.quorum SymbolTable.quorum ChainedActionCallOpcode.quorum JavaBytecodeOpcodes.quorum TableTester.quorum CheckContext.quorum ListTester.quorum TemplatingTester.quorum CheckDetectOpcode.quorum Location.quorum TextContext.quorum Class.quorum LoopContext.quorum TextObjectToTextPrimitiveCast.quorum ClassOpcode.quorum LoopOpcode.quorum TextPrimitiveToObjectCast.quorum ClassStatementsContext.quorum LoopsTester.quorum TextPrimitiveToTextObjectCast.quorum ClassTypeContext.quorum MathTester.quorum TextToBooleanCast.quorum ComparisonOpcode.quorum MeContext.quorum TextToIntegerCast.quorum Compiler.quorum MeOpcode.quorum TextToNumberCast.quorum CompilerError.quorum MeVariableAccessContext.quorum Type.quorum CompilerErrorManager.quorum MultiplicationContext.quorum CompilerErrorType.quorum NegateUnaryOpcode.quorum TypeCheckResult.quorum CompilerProfiler.quorum NoActionsNoClassContext.quorum TypeCheckTester.quorum CompilerTestResult.quorum NoClassDeclarationContext.quorum TypeChecker.quorum CompilerTestSuite.quorum NoClassStatementsContext.quorum TypeConversionConstants.quorum ConcatenateOpcode.quorum NoTypeAssignmentContext.quorum TypeConversionPoints.quorum ConditionalOpcode.quorum NormalAssignmentContext.quorum UnaryMinusContext.quorum ConstructorContext.quorum NotContext.quorum UnaryOpcode.quorum CreateObjectOpcode.quorum NumberContext.quorum UndefinedContext.quorum DecompresserTester.quorum NumberObjectToNumberPrimitiveCast.quorum UseContext.quorum Dependency.quorum NumberPrimitiveToNumberObjectCast.quorum UsePackageTester.quorum DetectBlockOpcode.quorum NumberPrimitiveToObjectCast.quorum Variable.quorum DetectStatementContext.quorum NumberToBooleanCast.quorum VariableFunctionCallContext.quorum Documentation.quorum NumberToIntegerCast.quorum EqualsContext.quorum NumberToTextCast.quorum
java -jar Default.jar -name Quorum -compile  main.quorum Hints/SetterGenerationHint.quorum Hints/GetterGenerationHint.quorum Compiler/Lexer.quorum Compiler/Token.quorum Documentation/Documentation.quorum Documentation/DocumentationGenerator.quorum Contexts/ParenthesisContext.quorum Contexts/NormalAssignmentContext.quorum Contexts/UnaryMinusContext.quorum Contexts/NumberContext.quorum Contexts/ActionContext.quorum Contexts/QualifiedNameContext.quorum Contexts/OutputContext.quorum Contexts/UseContext.quorum Contexts/DocumentationContext.quorum Contexts/AdditionContext.quorum Contexts/AlertContext.quorum Contexts/ActionsNoClassContext.quorum Contexts/FullClassDeclarationContext.quorum Contexts/MeVariableAccessContext.quorum Contexts/PackageContext.quorum Contexts/ReturnContext.quorum Contexts/BooleanContext.quorum Contexts/BlockContext.quorum Contexts/TextContext.quorum Contexts/InheritStatementsContext.quorum Contexts/NoActionsNoClassContext.quorum Contexts/InputContext.quorum Contexts/ActionCallContext.quorum Contexts/ParentVariableFunctionCallContext.quorum Contexts/NoClassDeclarationContext.quorum Contexts/NotContext.quorum Contexts/IsContext.quorum Contexts/InheritStatementContext.quorum Contexts/NoClassStatementsContext.quorum Contexts/IfContext.quorum Contexts/GenericDeclarationContext.quorum Contexts/AccessModifierContext.quorum Contexts/AlwaysStatementContext.quorum Contexts/ConstructorContext.quorum Contexts/StartContext.quorum Contexts/ClassStatementsContext.quorum Contexts/VariableFunctionCallContext.quorum Contexts/ParentFieldAccessContext.quorum Contexts/IntegerContext.quorum Contexts/ClassTypeContext.quorum Contexts/CheckContext.quorum Contexts/InequalityContext.quorum Contexts/EqualsContext.quorum Contexts/SayContext.quorum Contexts/StatementContext.quorum Contexts/DetectStatementContext.quorum Contexts/GenericContext.quorum Contexts/AndOrContext.quorum Contexts/NoTypeAssignmentContext.quorum Contexts/ParseContext.quorum Contexts/UndefinedContext.quorum Contexts/ActionExpressionListContext.quorum Contexts/ObjectAssignmentContext.quorum Contexts/AssignmentDeclaractionContext.quorum Contexts/ParentAssignmentContext.quorum Contexts/MultiplicationContext.quorum Contexts/ParentCallContext.quorum Contexts/FormalParameterContext.quorum Contexts/LoopContext.quorum Contexts/MeContext.quorum CompilerTestSuite.quorum Tests/BigIntegerTester.quorum Tests/ByteArrayTester.quorum Tests/TypeCheckTesterGenerated.quorum Tests/BitwiseTester.quorum Tests/SeparatedValueTester.quorum Tests/ExpressionsTester.quorum Tests/ActionsTester.quorum Tests/RandomTester.quorum Tests/MatrixTester.quorum Tests/TypeCheckTester.quorum Tests/StackTester.quorum Tests/CompilerTestResult.quorum Tests/JsonTester.quorum Tests/InheritanceTester.quorum Tests/ExceptionTester.quorum Tests/ListTester.quorum Tests/QueueTester.quorum Tests/TemplatingTesterGenerated.quorum Tests/FilesTester.quorum Tests/TemplatingTester.quorum Tests/DecompresserTester.quorum Tests/TableTester.quorum Tests/LoopsTester.quorum Tests/HashTableTester.quorum Tests/ChainingTester.quorum Tests/ArrayTester.quorum Tests/IfStatementTester.quorum Tests/UsePackageTester.quorum Tests/MathTester.quorum Completion/CodeCompletionRequest.quorum Completion/CodeCompletionItem.quorum Completion/CodeCompletionResult.quorum Completion/CodeCompletionHandler.quorum Bytecode/JavaBytecodeMethodWriter.quorum Bytecode/QuorumBytecodeListener.quorum Bytecode/JavaBytecodeOpcodes.quorum Bytecode/JavaBytecodeLabel.quorum Bytecode/QuorumJavascriptListener.quorum Bytecode/QuorumBytecodeConverter.quorum Bytecode/JarGenerator.quorum Bytecode/QuorumSourceListener.quorum Bytecode/JavaBytecodeFieldWriter.quorum Bytecode/JavaBytecodeClassWriter.quorum Symbols/TypeChecker.quorum Symbols/ActionCallResolution.quorum Symbols/SymbolTable.quorum Symbols/InferenceResult.quorum Symbols/Symbol.quorum Symbols/TypeCheckResult.quorum Symbols/Dependency.quorum Symbols/Action.quorum Symbols/Class.quorum Symbols/Type.quorum Symbols/Location.quorum Symbols/HashListIterator.quorum Symbols/GenericResolution.quorum Symbols/QualifiedName.quorum Symbols/NavigationBar.quorum Symbols/Source.quorum Symbols/ErrorBlockLabels.quorum Symbols/TypeConversionConstants.quorum Symbols/AlwaysBlockResource.quorum Symbols/ActionCall.quorum Symbols/Block.quorum Symbols/TypeConversionPoints.quorum Symbols/Variable.quorum Symbols/ClassAttribute.quorum Library.quorum Compiler/Parser.quorum Compiler/CompilerRequest.quorum Compiler/CompilerProfiler.quorum Compiler/CompilerErrorType.quorum Compiler/CompilerErrorManager.quorum Compiler/CompilerError.quorum Compiler/CompilerResult.quorum Compiler/Compiler.quorum Hints/UseHint.quorum Hints/AddReturnTypeHint.quorum Hints/Hint.quorum Opcodes/Operation.quorum Opcodes/Structures/BlockOpcode.quorum Opcodes/Structures/ClassOpcode.quorum Opcodes/Casts/TextToBooleanCast.quorum Opcodes/Casts/IntegerToTextCast.quorum Opcodes/Casts/NumberPrimitiveToObjectCast.quorum Opcodes/Casts/BooleanToTextOpcode.quorum Opcodes/Casts/ExplicitCastOpcode.quorum Opcodes/Casts/BooleanToNumberCast.quorum Opcodes/Casts/ObjectToPrimitiveBooleanCast.quorum Opcodes/Casts/IntegerPrimitiveToObjectCast.quorum Opcodes/Casts/CastContext.quorum Opcodes/Casts/IntegerPrimitiveToNumberObjectCast.quorum Opcodes/Casts/BooleanObjectToBooleanPrimitiveCast.quorum Opcodes/Casts/IntegerToBooleanCast.quorum Opcodes/Casts/NumberObjectToNumberPrimitiveCast.quorum Opcodes/Casts/AutoBoxReverseOpcode.quorum Opcodes/Casts/NumberToBooleanCast.quorum Opcodes/Casts/NumberToIntegerCast.quorum Opcodes/Casts/BooleanToTextCast.quorum Opcodes/Casts/ObjectToPrimitiveIntegerCast.quorum Opcodes/Casts/TextPrimitiveToTextObjectCast.quorum Opcodes/Casts/BooleanPrimitiveToObjectCast.quorum Opcodes/Casts/ObjectToPrimitiveNumberCast.quorum Opcodes/Casts/IntegerPrimitiveToIntegerObjectCast.quorum Opcodes/Casts/CastOpcode.quorum Opcodes/Casts/TextToNumberCast.quorum Opcodes/Casts/NumberPrimitiveToNumberObjectCast.quorum Opcodes/Casts/NumberToTextCast.quorum Opcodes/Casts/TextObjectToTextPrimitiveCast.quorum Opcodes/Casts/IntegerToNumberCast.quorum Opcodes/Casts/TextPrimitiveToObjectCast.quorum Opcodes/Casts/BooleanPrimitiveToBooleanObjectCast.quorum Opcodes/Casts/ObjectToPrimitiveTextCast.quorum Opcodes/Casts/TextToIntegerCast.quorum Opcodes/Casts/BooleanToIntegerCast.quorum Opcodes/Casts/IntegerObjectToIntegerPrimitiveCast.quorum Opcodes/UnaryOpcode.quorum Opcodes/QuorumConstant.quorum Opcodes/Statements/LoopOpcode.quorum Opcodes/Statements/ReturnOpcode.quorum Opcodes/Statements/MeOpcode.quorum Opcodes/Statements/AlertOpcode.quorum Opcodes/Statements/ConditionalOpcode.quorum Opcodes/Statements/OutputOpcode.quorum Opcodes/Statements/AssignmentOpcode.quorum Opcodes/Statements/SayOpcode.quorum Opcodes/Expressions/BinaryOpcode.quorum Opcodes/Expressions/NegateUnaryOpcode.quorum Opcodes/Expressions/CreateObjectOpcode.quorum Opcodes/Expressions/InputOpcode.quorum Opcodes/Expressions/BinaryAndOrOpcode.quorum Opcodes/Expressions/FlipBooleanOpcode.quorum Opcodes/Expressions/BlankOpcode.quorum Opcodes/Expressions/ComparisonOpcode.quorum Opcodes/Expressions/ConcatenateOpcode.quorum Opcodes/Expressions/IsOpcode.quorum Opcodes/Actions/ActionOpcode.quorum Opcodes/Actions/ChainedActionCallOpcode.quorum Opcodes/Actions/ActionCallOpcode.quorum Opcodes/Errors/CheckDetectOpcode.quorum Opcodes/Errors/DetectBlockOpcode.quorum Opcodes/QuorumOpcode.quorum

echo "Copying Quorum Next"
robocopy Run/ ./ /e /NFL /NDL /NJH /NJS /nc /ns /np

echo "Recompiling Quorum Next in Quorum Next"
rmdir /s /q Run
rmdir /s /q Build
REM java -jar Quorum.jar -name Quorum -compile main.quorum NavigationBar.quorum JsonTester.quorum MatrixTester.quorum DocumentationGenerator.quorum ClassAttribute.quorum CodeCompletionHandler.quorum Library.quorum CompilerRequest.quorum BitwiseTester.quorum FilesTester.quorum AddReturnTypeHint.quorum UseHint.quorum DocumentationContext.quorum CodeCompletionItem.quorum CodeCompletionRequest.quorum CodeCompletionResult.quorum CompilerResult.quorum TypeCheckTesterGenerated.quorum GenericResolution.quorum TemplatingTesterGenerated.quorum ChainingTester.quorum AccessModifierContext.quorum ErrorBlockLabels.quorum ObjectAssignmentContext.quorum Action.quorum ExceptionTester.quorum ObjectToPrimitiveBooleanCast.quorum ActionCall.quorum ExplicitCastOpcode.quorum ObjectToPrimitiveIntegerCast.quorum ActionCallContext.quorum ExpressionsTester.quorum ObjectToPrimitiveNumberCast.quorum ActionCallOpcode.quorum FlipBooleanOpcode.quorum ObjectToPrimitiveTextCast.quorum ActionCallResolution.quorum FormalParameterContext.quorum Operation.quorum ActionContext.quorum FullClassDeclarationContext.quorum OutputContext.quorum ActionExpressionListContext.quorum GenericContext.quorum OutputOpcode.quorum ActionOpcode.quorum GenericDeclarationContext.quorum PackageContext.quorum ActionsNoClassContext.quorum HashListIterator.quorum ParentAssignmentContext.quorum ActionsTester.quorum HashTableTester.quorum ParentCallContext.quorum AdditionContext.quorum Hint.quorum ParentFieldAccessContext.quorum AlertContext.quorum ParentVariableFunctionCallContext.quorum AlertOpcode.quorum IfContext.quorum ParenthesisContext.quorum AlwaysBlockResource.quorum IfStatementTester.quorum ParseContext.quorum AlwaysStatementContext.quorum InequalityContext.quorum Parser.quorum AndOrContext.quorum InferenceResult.quorum QualifiedName.quorum ArrayTester.quorum InheritStatementContext.quorum QualifiedNameContext.quorum AssignmentDeclaractionContext.quorum InheritStatementsContext.quorum QueueTester.quorum AssignmentOpcode.quorum InheritanceTester.quorum QuorumBytecodeConverter.quorum AutoBoxReverseOpcode.quorum InputContext.quorum QuorumBytecodeListener.quorum BinaryAndOrOpcode.quorum InputOpcode.quorum QuorumConstant.quorum BinaryOpcode.quorum IntegerContext.quorum QuorumJavascriptListener.quorum BlankOpcode.quorum IntegerObjectToIntegerPrimitiveCast.quorum QuorumOpcode.quorum Block.quorum IntegerPrimitiveToIntegerObjectCast.quorum QuorumSourceListener.quorum BlockContext.quorum IntegerPrimitiveToNumberObjectCast.quorum RandomTester.quorum BlockOpcode.quorum IntegerPrimitiveToObjectCast.quorum ReturnContext.quorum BooleanContext.quorum IntegerToBooleanCast.quorum ReturnOpcode.quorum BooleanObjectToBooleanPrimitiveCast.quorum IntegerToNumberCast.quorum SayContext.quorum BooleanPrimitiveToBooleanObjectCast.quorum IntegerToTextCast.quorum SayOpcode.quorum BooleanPrimitiveToObjectCast.quorum IsContext.quorum SeparatedValueTester.quorum BooleanToIntegerCast.quorum IsOpcode.quorum Source.quorum BooleanToNumberCast.quorum JarGenerator.quorum StackTester.quorum BooleanToTextCast.quorum JavaBytecodeClassWriter.quorum StartContext.quorum BooleanToTextOpcode.quorum JavaBytecodeFieldWriter.quorum StatementContext.quorum CastContext.quorum JavaBytecodeLabel.quorum Symbol.quorum CastOpcode.quorum JavaBytecodeMethodWriter.quorum SymbolTable.quorum ChainedActionCallOpcode.quorum JavaBytecodeOpcodes.quorum TableTester.quorum CheckContext.quorum ListTester.quorum TemplatingTester.quorum CheckDetectOpcode.quorum Location.quorum TextContext.quorum Class.quorum LoopContext.quorum TextObjectToTextPrimitiveCast.quorum ClassOpcode.quorum LoopOpcode.quorum TextPrimitiveToObjectCast.quorum ClassStatementsContext.quorum LoopsTester.quorum TextPrimitiveToTextObjectCast.quorum ClassTypeContext.quorum MathTester.quorum TextToBooleanCast.quorum ComparisonOpcode.quorum MeContext.quorum TextToIntegerCast.quorum Compiler.quorum MeOpcode.quorum TextToNumberCast.quorum CompilerError.quorum MeVariableAccessContext.quorum Type.quorum CompilerErrorManager.quorum MultiplicationContext.quorum CompilerErrorType.quorum NegateUnaryOpcode.quorum TypeCheckResult.quorum CompilerProfiler.quorum NoActionsNoClassContext.quorum TypeCheckTester.quorum CompilerTestResult.quorum NoClassDeclarationContext.quorum TypeChecker.quorum CompilerTestSuite.quorum NoClassStatementsContext.quorum TypeConversionConstants.quorum ConcatenateOpcode.quorum NoTypeAssignmentContext.quorum TypeConversionPoints.quorum ConditionalOpcode.quorum NormalAssignmentContext.quorum UnaryMinusContext.quorum ConstructorContext.quorum NotContext.quorum UnaryOpcode.quorum CreateObjectOpcode.quorum NumberContext.quorum UndefinedContext.quorum DecompresserTester.quorum NumberObjectToNumberPrimitiveCast.quorum UseContext.quorum Dependency.quorum NumberPrimitiveToNumberObjectCast.quorum UsePackageTester.quorum DetectBlockOpcode.quorum NumberPrimitiveToObjectCast.quorum Variable.quorum DetectStatementContext.quorum NumberToBooleanCast.quorum VariableFunctionCallContext.quorum Documentation.quorum NumberToIntegerCast.quorum EqualsContext.quorum NumberToTextCast.quorum
java -jar Default.jar -name Quorum -compile  main.quorum Hints/SetterGenerationHint.quorum Hints/GetterGenerationHint.quorum Compiler/Lexer.quorum Compiler/Token.quorum Documentation/Documentation.quorum Documentation/DocumentationGenerator.quorum Contexts/ParenthesisContext.quorum Contexts/NormalAssignmentContext.quorum Contexts/UnaryMinusContext.quorum Contexts/NumberContext.quorum Contexts/ActionContext.quorum Contexts/QualifiedNameContext.quorum Contexts/OutputContext.quorum Contexts/UseContext.quorum Contexts/DocumentationContext.quorum Contexts/AdditionContext.quorum Contexts/AlertContext.quorum Contexts/ActionsNoClassContext.quorum Contexts/FullClassDeclarationContext.quorum Contexts/MeVariableAccessContext.quorum Contexts/PackageContext.quorum Contexts/ReturnContext.quorum Contexts/BooleanContext.quorum Contexts/BlockContext.quorum Contexts/TextContext.quorum Contexts/InheritStatementsContext.quorum Contexts/NoActionsNoClassContext.quorum Contexts/InputContext.quorum Contexts/ActionCallContext.quorum Contexts/ParentVariableFunctionCallContext.quorum Contexts/NoClassDeclarationContext.quorum Contexts/NotContext.quorum Contexts/IsContext.quorum Contexts/InheritStatementContext.quorum Contexts/NoClassStatementsContext.quorum Contexts/IfContext.quorum Contexts/GenericDeclarationContext.quorum Contexts/AccessModifierContext.quorum Contexts/AlwaysStatementContext.quorum Contexts/ConstructorContext.quorum Contexts/StartContext.quorum Contexts/ClassStatementsContext.quorum Contexts/VariableFunctionCallContext.quorum Contexts/ParentFieldAccessContext.quorum Contexts/IntegerContext.quorum Contexts/ClassTypeContext.quorum Contexts/CheckContext.quorum Contexts/InequalityContext.quorum Contexts/EqualsContext.quorum Contexts/SayContext.quorum Contexts/StatementContext.quorum Contexts/DetectStatementContext.quorum Contexts/GenericContext.quorum Contexts/AndOrContext.quorum Contexts/NoTypeAssignmentContext.quorum Contexts/ParseContext.quorum Contexts/UndefinedContext.quorum Contexts/ActionExpressionListContext.quorum Contexts/ObjectAssignmentContext.quorum Contexts/AssignmentDeclaractionContext.quorum Contexts/ParentAssignmentContext.quorum Contexts/MultiplicationContext.quorum Contexts/ParentCallContext.quorum Contexts/FormalParameterContext.quorum Contexts/LoopContext.quorum Contexts/MeContext.quorum CompilerTestSuite.quorum Tests/BigIntegerTester.quorum Tests/ByteArrayTester.quorum Tests/TypeCheckTesterGenerated.quorum Tests/BitwiseTester.quorum Tests/SeparatedValueTester.quorum Tests/ExpressionsTester.quorum Tests/ActionsTester.quorum Tests/RandomTester.quorum Tests/MatrixTester.quorum Tests/TypeCheckTester.quorum Tests/StackTester.quorum Tests/CompilerTestResult.quorum Tests/JsonTester.quorum Tests/InheritanceTester.quorum Tests/ExceptionTester.quorum Tests/ListTester.quorum Tests/QueueTester.quorum Tests/TemplatingTesterGenerated.quorum Tests/FilesTester.quorum Tests/TemplatingTester.quorum Tests/DecompresserTester.quorum Tests/TableTester.quorum Tests/LoopsTester.quorum Tests/HashTableTester.quorum Tests/ChainingTester.quorum Tests/ArrayTester.quorum Tests/IfStatementTester.quorum Tests/UsePackageTester.quorum Tests/MathTester.quorum Completion/CodeCompletionRequest.quorum Completion/CodeCompletionItem.quorum Completion/CodeCompletionResult.quorum Completion/CodeCompletionHandler.quorum Bytecode/JavaBytecodeMethodWriter.quorum Bytecode/QuorumBytecodeListener.quorum Bytecode/JavaBytecodeOpcodes.quorum Bytecode/JavaBytecodeLabel.quorum Bytecode/QuorumJavascriptListener.quorum Bytecode/QuorumBytecodeConverter.quorum Bytecode/JarGenerator.quorum Bytecode/QuorumSourceListener.quorum Bytecode/JavaBytecodeFieldWriter.quorum Bytecode/JavaBytecodeClassWriter.quorum Symbols/TypeChecker.quorum Symbols/ActionCallResolution.quorum Symbols/SymbolTable.quorum Symbols/InferenceResult.quorum Symbols/Symbol.quorum Symbols/TypeCheckResult.quorum Symbols/Dependency.quorum Symbols/Action.quorum Symbols/Class.quorum Symbols/Type.quorum Symbols/Location.quorum Symbols/HashListIterator.quorum Symbols/GenericResolution.quorum Symbols/QualifiedName.quorum Symbols/NavigationBar.quorum Symbols/Source.quorum Symbols/ErrorBlockLabels.quorum Symbols/TypeConversionConstants.quorum Symbols/AlwaysBlockResource.quorum Symbols/ActionCall.quorum Symbols/Block.quorum Symbols/TypeConversionPoints.quorum Symbols/Variable.quorum Symbols/ClassAttribute.quorum Library.quorum Compiler/Parser.quorum Compiler/CompilerRequest.quorum Compiler/CompilerProfiler.quorum Compiler/CompilerErrorType.quorum Compiler/CompilerErrorManager.quorum Compiler/CompilerError.quorum Compiler/CompilerResult.quorum Compiler/Compiler.quorum Hints/UseHint.quorum Hints/AddReturnTypeHint.quorum Hints/Hint.quorum Opcodes/Operation.quorum Opcodes/Structures/BlockOpcode.quorum Opcodes/Structures/ClassOpcode.quorum Opcodes/Casts/TextToBooleanCast.quorum Opcodes/Casts/IntegerToTextCast.quorum Opcodes/Casts/NumberPrimitiveToObjectCast.quorum Opcodes/Casts/BooleanToTextOpcode.quorum Opcodes/Casts/ExplicitCastOpcode.quorum Opcodes/Casts/BooleanToNumberCast.quorum Opcodes/Casts/ObjectToPrimitiveBooleanCast.quorum Opcodes/Casts/IntegerPrimitiveToObjectCast.quorum Opcodes/Casts/CastContext.quorum Opcodes/Casts/IntegerPrimitiveToNumberObjectCast.quorum Opcodes/Casts/BooleanObjectToBooleanPrimitiveCast.quorum Opcodes/Casts/IntegerToBooleanCast.quorum Opcodes/Casts/NumberObjectToNumberPrimitiveCast.quorum Opcodes/Casts/AutoBoxReverseOpcode.quorum Opcodes/Casts/NumberToBooleanCast.quorum Opcodes/Casts/NumberToIntegerCast.quorum Opcodes/Casts/BooleanToTextCast.quorum Opcodes/Casts/ObjectToPrimitiveIntegerCast.quorum Opcodes/Casts/TextPrimitiveToTextObjectCast.quorum Opcodes/Casts/BooleanPrimitiveToObjectCast.quorum Opcodes/Casts/ObjectToPrimitiveNumberCast.quorum Opcodes/Casts/IntegerPrimitiveToIntegerObjectCast.quorum Opcodes/Casts/CastOpcode.quorum Opcodes/Casts/TextToNumberCast.quorum Opcodes/Casts/NumberPrimitiveToNumberObjectCast.quorum Opcodes/Casts/NumberToTextCast.quorum Opcodes/Casts/TextObjectToTextPrimitiveCast.quorum Opcodes/Casts/IntegerToNumberCast.quorum Opcodes/Casts/TextPrimitiveToObjectCast.quorum Opcodes/Casts/BooleanPrimitiveToBooleanObjectCast.quorum Opcodes/Casts/ObjectToPrimitiveTextCast.quorum Opcodes/Casts/TextToIntegerCast.quorum Opcodes/Casts/BooleanToIntegerCast.quorum Opcodes/Casts/IntegerObjectToIntegerPrimitiveCast.quorum Opcodes/UnaryOpcode.quorum Opcodes/QuorumConstant.quorum Opcodes/Statements/LoopOpcode.quorum Opcodes/Statements/ReturnOpcode.quorum Opcodes/Statements/MeOpcode.quorum Opcodes/Statements/AlertOpcode.quorum Opcodes/Statements/ConditionalOpcode.quorum Opcodes/Statements/OutputOpcode.quorum Opcodes/Statements/AssignmentOpcode.quorum Opcodes/Statements/SayOpcode.quorum Opcodes/Expressions/BinaryOpcode.quorum Opcodes/Expressions/NegateUnaryOpcode.quorum Opcodes/Expressions/CreateObjectOpcode.quorum Opcodes/Expressions/InputOpcode.quorum Opcodes/Expressions/BinaryAndOrOpcode.quorum Opcodes/Expressions/FlipBooleanOpcode.quorum Opcodes/Expressions/BlankOpcode.quorum Opcodes/Expressions/ComparisonOpcode.quorum Opcodes/Expressions/ConcatenateOpcode.quorum Opcodes/Expressions/IsOpcode.quorum Opcodes/Actions/ActionOpcode.quorum Opcodes/Actions/ChainedActionCallOpcode.quorum Opcodes/Actions/ActionCallOpcode.quorum Opcodes/Errors/CheckDetectOpcode.quorum Opcodes/Errors/DetectBlockOpcode.quorum Opcodes/QuorumOpcode.quorum

REM echo "Copying to NetBeans Installation"
REM rm ../../IDE/Sodbeans/Quorum/release/modules/ext/Quorum.jar
REM copy Run\Quorum.jar ..\..\IDE\Sodbeans\Quorum\release\modules\ext\Quorum.jar
REM copy Library\Compiled\Run\QuorumStandardLibrary.jar ..\..\IDE\Sodbeans\Quorum\release\modules\ext\QuorumStandardLibrary.jar
REM copy Library\Compiled\Run\QuorumStandardPlugins.jar ..\..\IDE\Sodbeans\Quorum\release\modules\ext\QuorumStandardPlugins.jar

REM By default, get rid of the library package and put it back in.
REM rmdir /s /q ..\..\..\sodbeans\Sodbeans\Quorum\release\modules\Library
REM robocopy Library ..\..\..\sodbeans\Sodbeans\Quorum\release\modules\Library /s /e /NFL /NDL /NJH /NJS /nc /ns /np

echo "Copying to New NetBeans Installation"
REM rm ../../IDE/Sodbeans/Quorum/release/modules/ext/Quorum.jar
copy Run\Quorum.jar ..\..\..\sodbeans\Sodbeans\Quorum\release\modules\ext\Quorum.jar
copy Library\Compiled\Run\QuorumStandardLibrary.jar ..\..\..\sodbeans\Sodbeans\Quorum\release\modules\ext\QuorumStandardLibrary.jar
copy Library\Compiled\Run\QuorumStandardPlugins.jar ..\..\..\sodbeans\Sodbeans\Quorum\release\modules\ext\QuorumStandardPlugins.jar

REM By default, get rid of the library package and put it back in.
rmdir /s /q ..\..\..\sodbeans\Sodbeans\Quorum\release\modules\Library
robocopy Library ..\..\..\sodbeans\Sodbeans\Quorum\release\modules\Library /s /e /NFL /NDL /NJH /NJS /nc /ns /np

rmdir /s /q "../../../quorumstudio/QuorumStudio/Library"
robocopy Library "../../../quorumstudio/QuorumStudio/Library" /s /e /NFL /NDL /NJH /NJS /nc /ns /np

echo "Copying Quorum to its final form."
mkdir ..\Quorum
copy Run\Quorum.jar ..\Quorum\Quorum.jar
copy Run\QuorumStandardLibrary.jar ..\Quorum\QuorumStandardLibrary.jar
copy Run\QuorumStandardPlugins.jar ..\Quorum\QuorumStandardPlugins.jar

robocopy Library ..\Quorum\Library /s /e /NFL /NDL /NJH /NJS /nc /ns /np

echo "Running test suite"
REM java -jar Quorum.jar -test

echo "Cleaning up Temporary Folders"
cd ..


rmdir /s /q Quorum3Compiler
REM If we don't want to store the final version, delete it.
rmdir /s /q Quorum
echo "Finished."