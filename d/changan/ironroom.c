// /d/changan/ironroom.c ��������

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������һ�ҳ�����һ�������̡������ߣ�һ�������õĴ���
���ӣ��Ա�¯���з��������������������������Ա߰�����������
�����һЩ�����õ���������Ĺ��߲��Ǻ��������ſڹ���һ
������(paizi)���򶫳����ݣ��������½֡�
LONG
        );

	set("item_desc",([
		"paizi" : "�߼��չ����������ף�������(pei)Կ�ף�����(xiuli)������\n",
]));
	set("exits", ([
	"east"          : __DIR__"eroad6",
	]) );

	set("objects",([
		__DIR__"npc/smith" :1,
]));
        setup();
	replace_program(ROOM);
}
