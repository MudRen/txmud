//sleeproom 无聊说者和三米的卧室

inherit ROOM;
inherit SHOW_MSG;

void create()
{
        set("short","绮红睡房");
        set("long", @LONG
这里是小山茅舍的睡房，阳光透过紫檀木的窗子里面照了过
来，你看见占据了睡房大部分的是一张大床，床上是一条绣了鸳
鸯的红色锦被，鸾帐低垂，里面传来一股幽幽的香气。另外屋里
只有一架梳妆台，上面放满了各种脂粉，看得你眼花缭乱。
LONG
        );

        set("night_long", @LONG
这里是小山茅舍的睡房，房里面燃着好几支红艳艳的蜡烛，
显得这里分外的温馨。借着烛光你看见睡房里面最显眼的是一张
大床，红色纱帐中传出一股幽幽的香气。不过听说无聊说者并不
在这里休息，他对三米还是发乎情止乎礼的。你一转眼看见旁边
有一架梳妆台，看看上面的脂粉，你不禁开始想象三米的美丽。
LONG
        );

	set("exits", ([
        "down":"/wiz/saying/workroom",
]));


	set(SAFE_ENV, 1);

	set("objects",([
        __DIR__"semi":1,
        "/obj/furniture/shuzhuangtai":1,
]));
        setup();
}
