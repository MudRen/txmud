// Room: /d/changan/chufang.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��������������ĺ����һλ�ϳ�ʦ���ڶ����׵�ʵϰ��ʦ
ָָ��㣬�Ա���һ����ˮ�ף�����С��������������ˮ����֤
��ʦ������ʱ��ˮ�á�
LONG
	);
        set(SAFE_ENV,1);
	set("exits",([
    "north" : __DIR__"jiulou",
]));
        set("resource/water",1);
	setup();
	replace_program(ROOM);
}
