// tong.c

inherit ITEM;

private int full;

int is_full() { return full != 0; }
void set_full(int n) { full = n; }

void create()
{
	set_name("ˮͰ", ({ "water bucket" }) );
	set_weight(100);

	set("long", "����һֻ��ͨ�Ĵ�ľͰ��ר���Ǵ�ˮ��(pour)���õġ�\n");
	set("unit", "ֻ");
	set("material", "wood");
        setup();
}

void init()
{
	full = 0;
}
