// nhroad1  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ǳ������ڻ�·���棬�ڻ�·���ڽ��ڻʹ��ڳǼ�֮��
�Ǹ����ŵ����ڵ����Խ���ɭ�ϣ���ʱ��Ѳ�Ǿ��Ӵ������߹���
�����ǹ��ҵ������ص�--���Ӽ࣬�ſ��йپ����أ���ʱ���Ĺ�
����ģ�����˳��룬�ű�ͣ�ż���С�Ρ�
LONG
        );
       set("exits", ([
                "west"             : __DIR__"nhroad2",
                "east"             : __DIR__"ehroad4",
                "north"            : "/d/guozijian/gzj_gate",
]) );
       set("outdoors","changan");
        setup();
	replace_program(ROOM);
}