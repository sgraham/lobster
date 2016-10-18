// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_BYTECODE_BYTECODE_H_
#define FLATBUFFERS_GENERATED_BYTECODE_BYTECODE_H_

#include "flatbuffers/flatbuffers.h"

namespace bytecode {

struct LineInfo;

struct Function;

struct Struct;

struct Ident;

struct SpecIdent;

struct BytecodeFile;

MANUALLY_ALIGNED_STRUCT(4) LineInfo FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t line_;
  int32_t fileidx_;
  int32_t bytecodestart_;

 public:
  LineInfo() { memset(this, 0, sizeof(LineInfo)); }
  LineInfo(const LineInfo &_o) { memcpy(this, &_o, sizeof(LineInfo)); }
  LineInfo(int32_t _line, int32_t _fileidx, int32_t _bytecodestart)
    : line_(flatbuffers::EndianScalar(_line)), fileidx_(flatbuffers::EndianScalar(_fileidx)), bytecodestart_(flatbuffers::EndianScalar(_bytecodestart)) { }

  int32_t line() const { return flatbuffers::EndianScalar(line_); }
  int32_t fileidx() const { return flatbuffers::EndianScalar(fileidx_); }
  int32_t bytecodestart() const { return flatbuffers::EndianScalar(bytecodestart_); }
};
STRUCT_END(LineInfo, 12);

MANUALLY_ALIGNED_STRUCT(4) SpecIdent FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t ididx_;
  int32_t typeidx_;

 public:
  SpecIdent() { memset(this, 0, sizeof(SpecIdent)); }
  SpecIdent(const SpecIdent &_o) { memcpy(this, &_o, sizeof(SpecIdent)); }
  SpecIdent(int32_t _ididx, int32_t _typeidx)
    : ididx_(flatbuffers::EndianScalar(_ididx)), typeidx_(flatbuffers::EndianScalar(_typeidx)) { }

  int32_t ididx() const { return flatbuffers::EndianScalar(ididx_); }
  int32_t typeidx() const { return flatbuffers::EndianScalar(typeidx_); }
};
STRUCT_END(SpecIdent, 8);

struct Function FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NAME = 4,
    VT_BYTECODESTART = 6
  };
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(VT_NAME); }
  int32_t bytecodestart() const { return GetField<int32_t>(VT_BYTECODESTART, 0); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyField<int32_t>(verifier, VT_BYTECODESTART) &&
           verifier.EndTable();
  }
};

struct FunctionBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(Function::VT_NAME, name); }
  void add_bytecodestart(int32_t bytecodestart) { fbb_.AddElement<int32_t>(Function::VT_BYTECODESTART, bytecodestart, 0); }
  FunctionBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  FunctionBuilder &operator=(const FunctionBuilder &);
  flatbuffers::Offset<Function> Finish() {
    auto o = flatbuffers::Offset<Function>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<Function> CreateFunction(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    int32_t bytecodestart = 0) {
  FunctionBuilder builder_(_fbb);
  builder_.add_bytecodestart(bytecodestart);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Function> CreateFunctionDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int32_t bytecodestart = 0) {
  return CreateFunction(_fbb, name ? _fbb.CreateString(name) : 0, bytecodestart);
}

struct Struct FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NAME = 4,
    VT_IDX = 6,
    VT_NFIELDS = 8
  };
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(VT_NAME); }
  int32_t idx() const { return GetField<int32_t>(VT_IDX, 0); }
  int32_t nfields() const { return GetField<int32_t>(VT_NFIELDS, 0); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyField<int32_t>(verifier, VT_IDX) &&
           VerifyField<int32_t>(verifier, VT_NFIELDS) &&
           verifier.EndTable();
  }
};

struct StructBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(Struct::VT_NAME, name); }
  void add_idx(int32_t idx) { fbb_.AddElement<int32_t>(Struct::VT_IDX, idx, 0); }
  void add_nfields(int32_t nfields) { fbb_.AddElement<int32_t>(Struct::VT_NFIELDS, nfields, 0); }
  StructBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  StructBuilder &operator=(const StructBuilder &);
  flatbuffers::Offset<Struct> Finish() {
    auto o = flatbuffers::Offset<Struct>(fbb_.EndTable(start_, 3));
    return o;
  }
};

inline flatbuffers::Offset<Struct> CreateStruct(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    int32_t idx = 0,
    int32_t nfields = 0) {
  StructBuilder builder_(_fbb);
  builder_.add_nfields(nfields);
  builder_.add_idx(idx);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Struct> CreateStructDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int32_t idx = 0,
    int32_t nfields = 0) {
  return CreateStruct(_fbb, name ? _fbb.CreateString(name) : 0, idx, nfields);
}

struct Ident FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NAME = 4,
    VT_READONLY = 6,
    VT_GLOBAL = 8
  };
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(VT_NAME); }
  bool readonly() const { return GetField<uint8_t>(VT_READONLY, 0) != 0; }
  bool global() const { return GetField<uint8_t>(VT_GLOBAL, 0) != 0; }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyField<uint8_t>(verifier, VT_READONLY) &&
           VerifyField<uint8_t>(verifier, VT_GLOBAL) &&
           verifier.EndTable();
  }
};

struct IdentBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(Ident::VT_NAME, name); }
  void add_readonly(bool readonly) { fbb_.AddElement<uint8_t>(Ident::VT_READONLY, static_cast<uint8_t>(readonly), 0); }
  void add_global(bool global) { fbb_.AddElement<uint8_t>(Ident::VT_GLOBAL, static_cast<uint8_t>(global), 0); }
  IdentBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  IdentBuilder &operator=(const IdentBuilder &);
  flatbuffers::Offset<Ident> Finish() {
    auto o = flatbuffers::Offset<Ident>(fbb_.EndTable(start_, 3));
    return o;
  }
};

inline flatbuffers::Offset<Ident> CreateIdent(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    bool readonly = false,
    bool global = false) {
  IdentBuilder builder_(_fbb);
  builder_.add_name(name);
  builder_.add_global(global);
  builder_.add_readonly(readonly);
  return builder_.Finish();
}

inline flatbuffers::Offset<Ident> CreateIdentDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    bool readonly = false,
    bool global = false) {
  return CreateIdent(_fbb, name ? _fbb.CreateString(name) : 0, readonly, global);
}

struct BytecodeFile FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_BYTECODE_VERSION = 4,
    VT_BYTECODE = 6,
    VT_TYPETABLE = 8,
    VT_STRINGTABLE = 10,
    VT_LINEINFO = 12,
    VT_FILENAMES = 14,
    VT_FUNCTIONS = 16,
    VT_STRUCTS = 18,
    VT_IDENTS = 20,
    VT_SPECIDENTS = 22,
    VT_DEFAULT_INT_VECTOR_TYPES = 24,
    VT_DEFAULT_FLOAT_VECTOR_TYPES = 26,
    VT_USES_FRAME_STATE = 28
  };
  int32_t bytecode_version() const { return GetField<int32_t>(VT_BYTECODE_VERSION, 0); }
  const flatbuffers::Vector<int32_t> *bytecode() const { return GetPointer<const flatbuffers::Vector<int32_t> *>(VT_BYTECODE); }
  const flatbuffers::Vector<int32_t> *typetable() const { return GetPointer<const flatbuffers::Vector<int32_t> *>(VT_TYPETABLE); }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *stringtable() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_STRINGTABLE); }
  const flatbuffers::Vector<const LineInfo *> *lineinfo() const { return GetPointer<const flatbuffers::Vector<const LineInfo *> *>(VT_LINEINFO); }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *filenames() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_FILENAMES); }
  const flatbuffers::Vector<flatbuffers::Offset<Function>> *functions() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Function>> *>(VT_FUNCTIONS); }
  const flatbuffers::Vector<flatbuffers::Offset<Struct>> *structs() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Struct>> *>(VT_STRUCTS); }
  const flatbuffers::Vector<flatbuffers::Offset<Ident>> *idents() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Ident>> *>(VT_IDENTS); }
  const flatbuffers::Vector<const SpecIdent *> *specidents() const { return GetPointer<const flatbuffers::Vector<const SpecIdent *> *>(VT_SPECIDENTS); }
  const flatbuffers::Vector<int32_t> *default_int_vector_types() const { return GetPointer<const flatbuffers::Vector<int32_t> *>(VT_DEFAULT_INT_VECTOR_TYPES); }
  const flatbuffers::Vector<int32_t> *default_float_vector_types() const { return GetPointer<const flatbuffers::Vector<int32_t> *>(VT_DEFAULT_FLOAT_VECTOR_TYPES); }
  bool uses_frame_state() const { return GetField<uint8_t>(VT_USES_FRAME_STATE, 0) != 0; }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_BYTECODE_VERSION) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_BYTECODE) &&
           verifier.Verify(bytecode()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_TYPETABLE) &&
           verifier.Verify(typetable()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_STRINGTABLE) &&
           verifier.Verify(stringtable()) &&
           verifier.VerifyVectorOfStrings(stringtable()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_LINEINFO) &&
           verifier.Verify(lineinfo()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_FILENAMES) &&
           verifier.Verify(filenames()) &&
           verifier.VerifyVectorOfStrings(filenames()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_FUNCTIONS) &&
           verifier.Verify(functions()) &&
           verifier.VerifyVectorOfTables(functions()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_STRUCTS) &&
           verifier.Verify(structs()) &&
           verifier.VerifyVectorOfTables(structs()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_IDENTS) &&
           verifier.Verify(idents()) &&
           verifier.VerifyVectorOfTables(idents()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SPECIDENTS) &&
           verifier.Verify(specidents()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_DEFAULT_INT_VECTOR_TYPES) &&
           verifier.Verify(default_int_vector_types()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_DEFAULT_FLOAT_VECTOR_TYPES) &&
           verifier.Verify(default_float_vector_types()) &&
           VerifyField<uint8_t>(verifier, VT_USES_FRAME_STATE) &&
           verifier.EndTable();
  }
};

struct BytecodeFileBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_bytecode_version(int32_t bytecode_version) { fbb_.AddElement<int32_t>(BytecodeFile::VT_BYTECODE_VERSION, bytecode_version, 0); }
  void add_bytecode(flatbuffers::Offset<flatbuffers::Vector<int32_t>> bytecode) { fbb_.AddOffset(BytecodeFile::VT_BYTECODE, bytecode); }
  void add_typetable(flatbuffers::Offset<flatbuffers::Vector<int32_t>> typetable) { fbb_.AddOffset(BytecodeFile::VT_TYPETABLE, typetable); }
  void add_stringtable(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> stringtable) { fbb_.AddOffset(BytecodeFile::VT_STRINGTABLE, stringtable); }
  void add_lineinfo(flatbuffers::Offset<flatbuffers::Vector<const LineInfo *>> lineinfo) { fbb_.AddOffset(BytecodeFile::VT_LINEINFO, lineinfo); }
  void add_filenames(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> filenames) { fbb_.AddOffset(BytecodeFile::VT_FILENAMES, filenames); }
  void add_functions(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Function>>> functions) { fbb_.AddOffset(BytecodeFile::VT_FUNCTIONS, functions); }
  void add_structs(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Struct>>> structs) { fbb_.AddOffset(BytecodeFile::VT_STRUCTS, structs); }
  void add_idents(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Ident>>> idents) { fbb_.AddOffset(BytecodeFile::VT_IDENTS, idents); }
  void add_specidents(flatbuffers::Offset<flatbuffers::Vector<const SpecIdent *>> specidents) { fbb_.AddOffset(BytecodeFile::VT_SPECIDENTS, specidents); }
  void add_default_int_vector_types(flatbuffers::Offset<flatbuffers::Vector<int32_t>> default_int_vector_types) { fbb_.AddOffset(BytecodeFile::VT_DEFAULT_INT_VECTOR_TYPES, default_int_vector_types); }
  void add_default_float_vector_types(flatbuffers::Offset<flatbuffers::Vector<int32_t>> default_float_vector_types) { fbb_.AddOffset(BytecodeFile::VT_DEFAULT_FLOAT_VECTOR_TYPES, default_float_vector_types); }
  void add_uses_frame_state(bool uses_frame_state) { fbb_.AddElement<uint8_t>(BytecodeFile::VT_USES_FRAME_STATE, static_cast<uint8_t>(uses_frame_state), 0); }
  BytecodeFileBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  BytecodeFileBuilder &operator=(const BytecodeFileBuilder &);
  flatbuffers::Offset<BytecodeFile> Finish() {
    auto o = flatbuffers::Offset<BytecodeFile>(fbb_.EndTable(start_, 13));
    return o;
  }
};

inline flatbuffers::Offset<BytecodeFile> CreateBytecodeFile(flatbuffers::FlatBufferBuilder &_fbb,
    int32_t bytecode_version = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> bytecode = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> typetable = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> stringtable = 0,
    flatbuffers::Offset<flatbuffers::Vector<const LineInfo *>> lineinfo = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> filenames = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Function>>> functions = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Struct>>> structs = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Ident>>> idents = 0,
    flatbuffers::Offset<flatbuffers::Vector<const SpecIdent *>> specidents = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> default_int_vector_types = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> default_float_vector_types = 0,
    bool uses_frame_state = false) {
  BytecodeFileBuilder builder_(_fbb);
  builder_.add_default_float_vector_types(default_float_vector_types);
  builder_.add_default_int_vector_types(default_int_vector_types);
  builder_.add_specidents(specidents);
  builder_.add_idents(idents);
  builder_.add_structs(structs);
  builder_.add_functions(functions);
  builder_.add_filenames(filenames);
  builder_.add_lineinfo(lineinfo);
  builder_.add_stringtable(stringtable);
  builder_.add_typetable(typetable);
  builder_.add_bytecode(bytecode);
  builder_.add_bytecode_version(bytecode_version);
  builder_.add_uses_frame_state(uses_frame_state);
  return builder_.Finish();
}

inline flatbuffers::Offset<BytecodeFile> CreateBytecodeFileDirect(flatbuffers::FlatBufferBuilder &_fbb,
    int32_t bytecode_version = 0,
    const std::vector<int32_t> *bytecode = nullptr,
    const std::vector<int32_t> *typetable = nullptr,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *stringtable = nullptr,
    const std::vector<const LineInfo *> *lineinfo = nullptr,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *filenames = nullptr,
    const std::vector<flatbuffers::Offset<Function>> *functions = nullptr,
    const std::vector<flatbuffers::Offset<Struct>> *structs = nullptr,
    const std::vector<flatbuffers::Offset<Ident>> *idents = nullptr,
    const std::vector<const SpecIdent *> *specidents = nullptr,
    const std::vector<int32_t> *default_int_vector_types = nullptr,
    const std::vector<int32_t> *default_float_vector_types = nullptr,
    bool uses_frame_state = false) {
  return CreateBytecodeFile(_fbb, bytecode_version, bytecode ? _fbb.CreateVector<int32_t>(*bytecode) : 0, typetable ? _fbb.CreateVector<int32_t>(*typetable) : 0, stringtable ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*stringtable) : 0, lineinfo ? _fbb.CreateVector<const LineInfo *>(*lineinfo) : 0, filenames ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*filenames) : 0, functions ? _fbb.CreateVector<flatbuffers::Offset<Function>>(*functions) : 0, structs ? _fbb.CreateVector<flatbuffers::Offset<Struct>>(*structs) : 0, idents ? _fbb.CreateVector<flatbuffers::Offset<Ident>>(*idents) : 0, specidents ? _fbb.CreateVector<const SpecIdent *>(*specidents) : 0, default_int_vector_types ? _fbb.CreateVector<int32_t>(*default_int_vector_types) : 0, default_float_vector_types ? _fbb.CreateVector<int32_t>(*default_float_vector_types) : 0, uses_frame_state);
}

inline const bytecode::BytecodeFile *GetBytecodeFile(const void *buf) { return flatbuffers::GetRoot<bytecode::BytecodeFile>(buf); }

inline const char *BytecodeFileIdentifier() { return "LBCF"; }

inline bool BytecodeFileBufferHasIdentifier(const void *buf) { return flatbuffers::BufferHasIdentifier(buf, BytecodeFileIdentifier()); }

inline bool VerifyBytecodeFileBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<bytecode::BytecodeFile>(BytecodeFileIdentifier()); }

inline const char *BytecodeFileExtension() { return "lbc"; }

inline void FinishBytecodeFileBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<bytecode::BytecodeFile> root) { fbb.Finish(root, BytecodeFileIdentifier()); }

}  // namespace bytecode

#endif  // FLATBUFFERS_GENERATED_BYTECODE_BYTECODE_H_
