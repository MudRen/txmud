// Room: /u/w/wangs/b/kai175.c

inherit ROOM;

void create()
{
    set("short", "С�ƹ�");
	set("long", @LONG
Ҫ�����ͬ������С�ƹݣ��������˲�֪�����˲�������
����Щ�ڹ���������������ˣ�����ÿ��ǵ����С�ƹݴ��ת
���ɣ��������Լ�Ҳ�㲻�徿����Ϊ�˺Ⱦƣ�����Ϊ��ȥ���͹�
̨���ϰ����Ǹ����µ�Ů����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai174",
]));

        set("objects",([
        __DIR__"npc/tbboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
