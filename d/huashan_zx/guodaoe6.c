// Room: guodaoe6.c by pian
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long",@LONG
����һ�����������Ļ��ȣ������ϻ��Ķ��ǵ���������
�����Ǳ��ɵ�ʲô��ʰɡ����Ȼ���������ǰԺ��ǰԺ��ʵ����
һ����С�Ļ�԰��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southeast" : __DIR__"guodaoe5",
	"northwest" : __DIR__"guodaoe7",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}