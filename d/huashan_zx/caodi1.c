// Room: caodi.c by pian

inherit ROOM;
void create()
{
	set("short","�ݵ�");
	set("long",@LONG
������һһƬ�ݵأ������Щ������̺��С����׺��䣬
�������ᣬ������һ��СС��ʯͤ��������Ժ�������ʯ�ס�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"ting2",
	"west":__DIR__"shidao2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}