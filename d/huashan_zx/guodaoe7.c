// Room: guodaoe7.c by pian
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
	"southeast" : __DIR__"guodaoe6",
	"northwest" : __DIR__"guodaoe8",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}