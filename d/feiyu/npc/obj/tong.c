// tong.c

inherit ITEM;

private int full;

int is_full() { return full != 0; }
void set_full(int n) { full = n; }

void create()
{
	set_name("水桶", ({ "water bucket" }) );
	set_weight(100);

	set("long", "这是一只普通的大木桶，专门是打水浇(pour)地用的。\n");
	set("unit", "只");
	set("material", "wood");
        setup();
}

void init()
{
	full = 0;
}
