// Room: guange.c by pian
inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
������һƬ�������ߵķ����֡�ʱֵ������־�Ⱦ��Ϧ��
��磬����ͳ�����ô��������������������֮�࣬��Ҳ��Щ��
���⡣ԶԶ����������һ��СС�Ĳ�ͤ��������Ĺ����������
�ᴫ����
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"gongmen",
	"east":__DIR__"guange2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}