// hoe.c

inherit ITEM;

void create()
{
	set_name("药锄", ({ "medicine hoe" }) );
	set_weight(100);

	set("long", "这是一把铜头竹杆的小锄头，可以用来锄(hoe)地。\n");
	set("unit", "把");
	set("material", "wood");
        setup();
}
