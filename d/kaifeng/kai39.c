// Room: /u/w/wangs/b/kai39.c

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
�߽����һ�������Ĺ����˱Ƕ��������еĻ����ϸ��ֹ�
Ʒ������Ŀ�����⸮�Ľ�ͨ������Ը���ʱ�ʵĹ�Ʒ������С�
����ֵ��Ǻܶ಻��������ڵĹ������Ҳ�ܿ�������˵������
�����ʣ����������صظ����㣬����һ�ַǳ�����ķ��ӣ�����
��ˮ����źܳ�ʱ���������ʡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai37",
]));

        set("objects",([
        __DIR__"npc/sgboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
