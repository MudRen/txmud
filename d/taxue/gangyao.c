// gangyao.c
// by dicky

inherit ROOM;

void create()
{
	set("short","��Ҥ");
        set("long",@LONG
�����������һ��ŨŨ�ľ����⣬���ڿ�������ͨ���е�һ˿˿ͷ
�Ρ�͸��ǽ���ϵ���⣬��ϡ���Կ���һ����ͻ���С���������涼����
���ӡ�ԭ�����������Ƶĵط���
LONG);

	set("exits",([
		"up" : __DIR__"zaofang",
	]));

	setup();
	replace_program(ROOM);
}
