// Room: /wiz/louth/c/tiejiangpu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǳɶ���һ����ͨ�������̣�һ��ȥ���ܿ�������ǽ����
����������������ǽ��Զ�ĵط���һ�Ŵ����õ����ӣ������
�ż��Ѹճ�¯�ı������űߵ�һ��ľ��(pai)����д�ŵ�ʲô����
���򶫾�����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wwdao5",
]));

	set("item_desc",([
	"pai" : "�߼��չ����������ף�������(pei)Կ�ף�����(xiuli)������\n",
]));

	set("objects",([
	__DIR__"npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
