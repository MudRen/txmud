// wpear.c
inherit ITEM;
void create()
{
  set_name("ľ��", ({ "wood pear" }) );
  set_weight(500);
  if( clonep() )
          set_default_object(__FILE__);
  else {
          set("long", "һֻľ���Ѽ�档\n");
          set("unit", "��");
          set("value", 50);
          set("food_remaining", 4);
          set("food_supply", 20);
  }
  setup();
}
