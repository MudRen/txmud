// Room: guodaoe5.c by pian
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long",@LONG
����һ�����������Ļ��ȣ������ϻ��Ķ��ǵ���������
�����Ǳ��ɵ�ʲô��ʰɡ����Ȼ���������ǰԺ��ǰԺ��ʵ����
һ����С�Ļ�԰������������ˮ����ɢ�����϶��е㳱ʪ�ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"southwest" : __DIR__"guodaoe4",
	"northwest" : __DIR__"guodaoe6",
	//"east":__DIR__"longbi4",
	"west":__DIR__"feihua2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}