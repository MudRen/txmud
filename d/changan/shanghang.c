// Room: /d/changan/shanghang.c

inherit SHOP;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ�䲻��ĵ��棬�������߰���İ��Ÿ�ʽ�����Ķ�����
С��һ��һ�룬���鱦�Ŷ�ʲô���У�һ������һ���չ�����
��Ʒ�Ķ����������С���������һ���ֿ⣬�ſڹ���һ������
(paizi)��֪д��Щʲô��
LONG
	);

	set("item_desc", ([
	"paizi" : "�չ���ʽ��Ʒ����Ѵ��͹��ۡ�\n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"eroad3",
]));

	set("objects",([
	__DIR__"npc/shop_waiter" : 1,
]));

	setup();
}