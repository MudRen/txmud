// Room: /d/jinghai/th03.c

inherit ROOM;

void create()
{
        set("short", "�һ�ɽׯ����");
        set("long", @LONG
�һ�ɽׯ�ĳ��š����߳����ĳ�ǽ����ʯ���ͣ�������һ������
�ĳ�¥���������Ȼ�ͭ��Ӳľ���ţ�����˫����ʯ������ͨ��
ׯ���⡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"wm5",
  "northup" : __DIR__"wm4",
  "eastdown" : __DIR__"th02",
  "west" : __DIR__"wm8",
]));
        set("objects",([
        __DIR__"npc/yong5" : 2,
        __DIR__"npc/duizhang1.c" : 1 ,
]));

        set("outdoors","jinghai");

        setup();
        replace_program(ROOM);
}
