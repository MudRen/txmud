// Room: doorgd.c by pian
inherit ROOM;

void create()
{
	set("short", "ǰ������");
	set("long",@LONG
̤����ϼ�����ţ�������һ���������������ȣ���������ɨ
�ļ��Ǹɾ����򱱿��Կ���һ���Ϻ�ɫ��Ӱ�ڡ�������һ��СС
���ŷ���
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"yingbi",
	"south" : __DIR__"gongmen",
	"east" : __DIR__"guarde",
]));
	set("indoors", "huashan_p");
	setup();
	replace_program(ROOM);
}