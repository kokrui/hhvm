/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;
import com.facebook.thrift.*;
import com.facebook.thrift.annotations.*;
import com.facebook.thrift.async.*;
import com.facebook.thrift.meta_data.*;
import com.facebook.thrift.server.*;
import com.facebook.thrift.transport.*;
import com.facebook.thrift.protocol.*;

/**
 * A patch for a boolean value.
 */
@SuppressWarnings({ "unused", "serial" })
public class BoolPatch implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("BoolPatch");
  private static final TField ASSIGN_FIELD_DESC = new TField("assign", TType.BOOL, (short)1);
  private static final TField CLEAR_FIELD_DESC = new TField("clear", TType.BOOL, (short)2);
  private static final TField INVERT_FIELD_DESC = new TField("invert", TType.BOOL, (short)9);

  /**
   * Assigns to a (set) value.
   * 
   * If set, all other patch operations are ignored.
   * 
   * Note: Only modifies set field values.
   */
  public final Boolean assign;
  /**
   * Clear any set value.
   */
  public final Boolean clear;
  /**
   * If the bool value should be inverted.
   */
  public final Boolean invert;
  public static final int ASSIGN = 1;
  public static final int CLEAR = 2;
  public static final int INVERT = 9;

  public BoolPatch(
      Boolean assign,
      Boolean clear,
      Boolean invert) {
    this.assign = assign;
    this.clear = clear;
    this.invert = invert;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public BoolPatch(BoolPatch other) {
    if (other.isSetAssign()) {
      this.assign = TBaseHelper.deepCopy(other.assign);
    } else {
      this.assign = null;
    }
    if (other.isSetClear()) {
      this.clear = TBaseHelper.deepCopy(other.clear);
    } else {
      this.clear = null;
    }
    if (other.isSetInvert()) {
      this.invert = TBaseHelper.deepCopy(other.invert);
    } else {
      this.invert = null;
    }
  }

  public BoolPatch deepCopy() {
    return new BoolPatch(this);
  }

  /**
   * Assigns to a (set) value.
   * 
   * If set, all other patch operations are ignored.
   * 
   * Note: Only modifies set field values.
   */
  public Boolean isAssign() {
    return this.assign;
  }

  // Returns true if field assign is set (has been assigned a value) and false otherwise
  public boolean isSetAssign() {
    return this.assign != null;
  }

  /**
   * Clear any set value.
   */
  public Boolean isClear() {
    return this.clear;
  }

  // Returns true if field clear is set (has been assigned a value) and false otherwise
  public boolean isSetClear() {
    return this.clear != null;
  }

  /**
   * If the bool value should be inverted.
   */
  public Boolean isInvert() {
    return this.invert;
  }

  // Returns true if field invert is set (has been assigned a value) and false otherwise
  public boolean isSetInvert() {
    return this.invert != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof BoolPatch))
      return false;
    BoolPatch that = (BoolPatch)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetAssign(), that.isSetAssign(), this.assign, that.assign)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetClear(), that.isSetClear(), this.clear, that.clear)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetInvert(), that.isSetInvert(), this.invert, that.invert)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {assign, clear, invert});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static BoolPatch deserialize(TProtocol iprot) throws TException {
    Boolean tmp_assign = null;
    Boolean tmp_clear = null;
    Boolean tmp_invert = null;
    TField __field;
    iprot.readStructBegin();
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        case ASSIGN:
          if (__field.type == TType.BOOL) {
            tmp_assign = iprot.readBool();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case CLEAR:
          if (__field.type == TType.BOOL) {
            tmp_clear = iprot.readBool();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case INVERT:
          if (__field.type == TType.BOOL) {
            tmp_invert = iprot.readBool();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(iprot, __field.type);
          break;
      }
      iprot.readFieldEnd();
    }
    iprot.readStructEnd();

    BoolPatch _that;
    _that = new BoolPatch(
      tmp_assign
      ,tmp_clear
      ,tmp_invert
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.assign != null) {
      if (isSetAssign()) {
        oprot.writeFieldBegin(ASSIGN_FIELD_DESC);
        oprot.writeBool(this.assign);
        oprot.writeFieldEnd();
      }
    }
    if (this.clear != null) {
      oprot.writeFieldBegin(CLEAR_FIELD_DESC);
      oprot.writeBool(this.clear);
      oprot.writeFieldEnd();
    }
    if (this.invert != null) {
      oprot.writeFieldBegin(INVERT_FIELD_DESC);
      oprot.writeBool(this.invert);
      oprot.writeFieldEnd();
    }
    oprot.writeFieldStop();
    oprot.writeStructEnd();
  }

  @Override
  public String toString() {
    return toString(1, true);
  }

  @Override
  public String toString(int indent, boolean prettyPrint) {
    return TBaseHelper.toStringHelper(this, indent, prettyPrint);
  }

  public void validate() throws TException {
    // check for required fields
  }

}

