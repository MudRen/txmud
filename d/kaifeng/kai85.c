// Room: /u/w/wangs/b/kai85.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ��ܴ�������̣�����������ż�����¯�ӣ���Χ
�����˸�ʽ�����ı������Ʒ������С�����æµ�š���������
���������£����������䡣���������������ǳ��á����ŵ�
�ſ��϶���һ������(paizi)��
LONG
);

	set("item_desc",([
	"paizi" : "\n�߼��չ�����������\n������(pei)Կ��\n����(xiuli)������\n\n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai83",
]));

	set("objects",([
	__DIR__"npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
