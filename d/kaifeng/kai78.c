// Room: /u/w/wangs/b/kai78.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������˵Ҳ���ϱ��Ǽ��䳡�����˿��ġ��������
�赶Ūǹ�����㿪��ݽ���ʹ��ʹ�������������������裬����
����۹���ʵ���������Ҿ�˵������˻����㿪һ��ҽի����ҽ
�ε��ˣ��ٿ�һ�ҹײ���ר�Ÿ���Щѧ���书�ĺö���������ʬ
���ᡣ������̴�����֮�죬����ǰ;�ز���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kai72",
  "east" : __DIR__"kai77",
]));

        set("objects",([
        __DIR__"npc/tielaoban" : 1,
]));

	setup();
	replace_program(ROOM);
}
