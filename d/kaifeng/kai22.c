// Room: /u/w/wangs/b/kai22.c

inherit ROOM;

void create()
{
	set("short", "С���");
	set("long", @LONG
����һ�Һ��ϵĲ�ݣ���ǰ���⻹���ǳǵ�ʱ�����������
�ط��ˡ���������ΰ�ʾ㶼�������Ƴɣ����������Զ��ȫ��
ɢ����һĨ���Ƶ��͹⣬ʹ������ӵĹ�ɫ���㡣�����˰����裬
ÿ�������������������ϯ����һ��������죬����˵����
�����۹Ž�����Ҳ���ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai21",
]));
        set("objects",([
        __DIR__"npc/tuobei" : 1,
]));

	setup();
	replace_program(ROOM);
}
