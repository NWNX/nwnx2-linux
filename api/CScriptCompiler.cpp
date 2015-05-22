#include "CScriptCompiler.h"

int CScriptCompiler::AddStructureToStack(CExoString const &, int)
{
    asm("leave");
    asm("mov $0x08252c30, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::AddSymbolToLabelList(int, int, int, int)
{
    asm("leave");
    asm("mov $0x08252f48, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::AddSymbolToQueryList(int, int, int, int)
{
    asm("leave");
    asm("mov $0x082530e8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::AddToGlobalVariableList(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x0825e4fc, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::AddToSymbolTableVarStack(int, int, int)
{
    asm("leave");
    asm("mov $0x08253538, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::AddUserDefinedIdentifier(CScriptParseTreeNode *, int)
{
    asm("leave");
    asm("mov $0x0825cfc4, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::AddVariableToStack(int, CExoString *, int)
{
    asm("leave");
    asm("mov $0x08252aa8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::CheckForBadLValue(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x0825e4bc, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::CleanUpAfterCompile(int, CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x08248c60, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::CleanUpAfterCompiles()
{
    asm("leave");
    asm("mov $0x08245d78, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::CleanUpDuringCompile(int)
{
    asm("leave");
    asm("mov $0x0825e11c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ClearAllSymbolLists()
{
    asm("leave");
    asm("mov $0x08254f10, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ClearCompiledScriptCode()
{
    asm("leave");
    asm("mov $0x08247f90, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ClearSwitchLabelList()
{
    asm("leave");
    asm("mov $0x0824a0b8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ClearUserDefinedIdentifiers()
{
    asm("leave");
    asm("mov $0x0824897c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::CompileFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x08245e8c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::CompileScriptChunk(CExoString const &)
{
    asm("leave");
    asm("mov $0x08246248, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::CompileScriptConditional(CExoString const &)
{
    asm("leave");
    asm("mov $0x0824632c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::CreateScriptParseTreeNode(int, CScriptParseTreeNode *, CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x08258388, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::DeleteCompileStack()
{
    asm("leave");
    asm("mov $0x0825e560, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::DeleteParseTree(int, CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x08247e38, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::DeleteScriptParseTreeNode(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x0825e404, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::DetermineLocationOfCode()
{
    asm("leave");
    asm("mov $0x082493c4, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::DuplicateScriptParseTree(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x082584dc, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::EndLineNumberAtBinaryInstruction(int, int, int)
{
    asm("leave");
    asm("mov $0x08253304, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::FinalizeFinalCode()
{
    asm("leave");
    asm("mov $0x08254e80, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::FoundReturnStatementOnAllBranches(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x08252a08, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GenerateCodeForSwitchLabels(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x08255000, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GenerateDebuggerTypeAbbreviation(int, CExoString)
{
    asm("leave");
    asm("mov $0x08253e6c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GenerateFinalCodeFromParseTree(CExoString)
{
    asm("leave");
    asm("mov $0x08248440, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GenerateIdentifierList()
{
    asm("leave");
    asm("mov $0x08255378, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GenerateIdentifiersFromConstantVariables(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x0824a214, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GenerateParseTree()
{
    asm("leave");
    asm("mov $0x08258610, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GetCompiledScriptCode(char **, int *)
{
    asm("leave");
    asm("mov $0x08247f6c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GetFunctionNameFromSymbolSubTypes(int, int)
{
    asm("leave");
    asm("mov $0x08252e54, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GetHashEntryByName(char const *)
{
    asm("leave");
    asm("mov $0x08245640, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GetIdentifierByName(CExoString const &)
{
    asm("leave");
    asm("mov $0x08255114, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GetNewScriptParseTreeNode()
{
    asm("leave");
    asm("mov $0x08258020, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GetStructureField(CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082551c8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::GetStructureSize(CExoString const &)
{
    asm("leave");
    asm("mov $0x082550bc, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::HandleIdentifierToken()
{
    asm("leave");
    asm("mov $0x08257e94, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::HandleToken()
{
    asm("leave");
    asm("mov $0x08257e54, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::HashManagerAdd(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082457b8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::HashManagerDelete(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08245980, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::HashString(char const *)
{
    asm("leave");
    asm("mov $0x08247be8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::HashString(CExoString const &)
{
    asm("leave");
    asm("mov $0x08247c44, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::InVisitGenerateCode(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x0824ba14, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::InitializeFinalCode()
{
    asm("leave");
    asm("mov $0x08254e0c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::InitializeIncludeFile(int)
{
    asm("leave");
    asm("mov $0x08247d78, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::InitializePreDefinedStructures()
{
    asm("leave");
    asm("mov $0x08247cb0, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::InitializeSwitchLabelList()
{
    asm("leave");
    asm("mov $0x08254fc0, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::Initialize()
{
    asm("leave");
    asm("mov $0x08243c90, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::InsertGlobalVariablesInParseTree(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x08254f88, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::InstallLoader()
{
    asm("leave");
    asm("mov $0x08248e40, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ModifySRStackReturnTree(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x0825e3e0, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::OutputError(int, CExoString *, int, CExoString const &)
{
    asm("leave");
    asm("mov $0x08246410, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::OutputIdentifierError(CExoString const &, int, int)
{
    asm("leave");
    asm("mov $0x08249660, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::OutputWalkTreeError(int, CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x08248d4c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterAlphabet(int)
{
    asm("leave");
    asm("mov $0x08256598, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterAmpersand(int)
{
    asm("leave");
    asm("mov $0x082576b8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterAsterisk(int)
{
    asm("leave");
    asm("mov $0x0825779c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterCarat(int)
{
    asm("leave");
    asm("mov $0x08257ce0, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterColon()
{
    asm("leave");
    asm("mov $0x08257e20, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterComma()
{
    asm("leave");
    asm("mov $0x08257d6c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterEllipsis()
{
    asm("leave");
    asm("mov $0x08257da0, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterEqualSign(int)
{
    asm("leave");
    asm("mov $0x08257b80, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterExclamationPoint(int)
{
    asm("leave");
    asm("mov $0x08257b24, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterHyphen(int)
{
    asm("leave");
    asm("mov $0x08257978, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterLeftAngle(int)
{
    asm("leave");
    asm("mov $0x08256754, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterLeftBrace()
{
    asm("leave");
    asm("mov $0x082579ec, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterLeftBracket()
{
    asm("leave");
    asm("mov $0x08257a54, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterLeftSquareBracket()
{
    asm("leave");
    asm("mov $0x08257abc, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterNumeric(int)
{
    asm("leave");
    asm("mov $0x082575a8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterPercentSign(int)
{
    asm("leave");
    asm("mov $0x08257c50, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterPeriod()
{
    asm("leave");
    asm("mov $0x082564e8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterPlusSign(int)
{
    asm("leave");
    asm("mov $0x08257bdc, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterQuestionMark()
{
    asm("leave");
    asm("mov $0x08257dec, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterQuotationMark()
{
    asm("leave");
    asm("mov $0x08257930, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterRightAngle(int)
{
    asm("leave");
    asm("mov $0x08256678, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterRightBrace()
{
    asm("leave");
    asm("mov $0x08257a20, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterRightBracket()
{
    asm("leave");
    asm("mov $0x08257a88, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterRightSquareBracket()
{
    asm("leave");
    asm("mov $0x08257af0, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterSemicolon()
{
    asm("leave");
    asm("mov $0x08257cac, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterSlash(int)
{
    asm("leave");
    asm("mov $0x0825762c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterTilde()
{
    asm("leave");
    asm("mov $0x08257d38, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCharacterVerticalBar(int)
{
    asm("leave");
    asm("mov $0x08257728, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseCommentedOutCharacter(int)
{
    asm("leave");
    asm("mov $0x082577f4, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseFloatFromTokenString()
{
    asm("leave");
    asm("mov $0x08256428, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseIdentifierFile()
{
    asm("leave");
    asm("mov $0x0825625c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseNextCharacter(int, int)
{
    asm("leave");
    asm("mov $0x0825695c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseSource(char *, int)
{
    asm("leave");
    asm("mov $0x0825e1cc, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ParseStringCharacter(int, int)
{
    asm("leave");
    asm("mov $0x08257874, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::PopSRStack(int *, int *, int *, CScriptParseTreeNode **, CScriptParseTreeNode **)
{
    asm("leave");
    asm("mov $0x0825e328, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::PostVisitGenerateCode(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x0824c7e4, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::PreVisitGenerateCode(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x0824a688, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::PrintBinaryAddress()
{
    asm("leave");
    asm("mov $0x08255090, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::PrintParseIdentifierFileError(int)
{
    asm("leave");
    asm("mov $0x08256188, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::PrintParseSourceError(int)
{
    asm("leave");
    asm("mov $0x0825dfa8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::PushSRStack(int, int, int, CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x08257ef0, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::RemoveFromSymbolTableVarStack(int, int, int)
{
    asm("leave");
    asm("mov $0x08253888, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ResolveDebuggingInformationForIdentifier(int)
{
    asm("leave");
    asm("mov $0x08253c64, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ResolveDebuggingInformation()
{
    asm("leave");
    asm("mov $0x082552e8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ResolveLabels()
{
    asm("leave");
    asm("mov $0x082497a0, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::SetAutomaticCleanUpAfterCompiles(int)
{
    asm("leave");
    asm("mov $0x08247f58, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::SetCompileConditionalFile(int)
{
    asm("leave");
    asm("mov $0x08247f30, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::SetCompileConditionalOrMain(int)
{
    asm("leave");
    asm("mov $0x08247f44, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::SetCompileDebugLevel(int)
{
    asm("leave");
    asm("mov $0x08247ec8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::SetCompileSymbolicOutput(int)
{
    asm("leave");
    asm("mov $0x08247ef0, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::SetGenerateDebuggerOutput(int)
{
    asm("leave");
    asm("mov $0x08247edc, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::SetIdentifierSpecification(CExoString const &)
{
    asm("leave");
    asm("mov $0x08245b64, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::SetOptimizeBinaryCodeLength(int)
{
    asm("leave");
    asm("mov $0x08247f1c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::SetOutputAlias(CExoString const &)
{
    asm("leave");
    asm("mov $0x08247f04, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ShutDown()
{
    asm("leave");
    asm("mov $0x08243a24, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ShutdownIncludeFile(int)
{
    asm("leave");
    asm("mov $0x08247de8, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::StartLineNumberAtBinaryInstruction(int, int, int)
{
    asm("leave");
    asm("mov $0x0825527c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::TestIdentifierToken()
{
    asm("leave");
    asm("mov $0x082567f4, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::Test_CompareDirectoryContents(CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x08246e3c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::Test_CompareFileInclusion(CExoString &, CExoString &, CExoStringList *, unsigned short)
{
    asm("leave");
    asm("mov $0x08247610, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::Test_CompileAllScriptsInDirectory(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x0824665c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::TokenInitialize()
{
    asm("leave");
    asm("mov $0x0825e30c, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::TraverseTreeForSwitchLabels(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x08249c98, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::ValidateLocationOfIdentifier(CExoString const &)
{
    asm("leave");
    asm("mov $0x082494a0, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::WalkParseTree(CScriptParseTreeNode *)
{
    asm("leave");
    asm("mov $0x08253210, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::WriteDebuggerOutputToFile(CExoString)
{
    asm("leave");
    asm("mov $0x08254014, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::WriteFinalCodeToFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x08248670, %eax");
    asm("jmp *%eax");
}

int CScriptCompiler::WriteResolvedOutput()
{
    asm("leave");
    asm("mov $0x0824a580, %eax");
    asm("jmp *%eax");
}

