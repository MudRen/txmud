//cook_room.c ͷ�˸�������
inherit ROOM;
void create()
{
        set("short","����");
        set("long", @LONG
������ͷ�˸��ĳ���������ȫ���Ļ�ʳ���Ա߻���һ��С��
�䣬��ר�Ÿ���ү̫̫�������ĵط�����Ȼ�������ܴ󣬲�����
���ʦ���ǻ������������æ�ţ����ҳ���Ҳ�����ࡣ
LONG
        );
        set("exits", ([
        "north":__DIR__"garden",
]));
        set("objects",([
        __DIR__"npc/cook":1,
]));
        setup();
}
