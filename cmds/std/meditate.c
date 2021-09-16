// meditate.c
// by Find.

#include <ansi.h>
inherit F_CLEAN_UP;

string *m_msg = ({
"蔚蓝的天空下是一望无际的草原，草原上羊群边站着一个牧童，
手里拿着一只金色的笛子，正在吹奏着悠扬的曲子",
"大地一片昏暗，天空中乌云翻滚，一条金龙在云层中穿梭，不时
的发出惊天动地的鸣叫，仿佛预示着世界的毁灭",
"黄土地上躺满了死尸，血流成河，一位白衣侠士站在你的面前，
手拿一把滴血的宝剑，两眼迷惘的望着前方",
"碧云天，黄花地，清风拂面，不远处一位美丽清秀的少女手拿一
枝玫瑰缓缓地向你走来",
"昏黄的夕阳映照着无边无际的沙漠，远方一只驼队在缓缓的移动，
不时传来叮叮当当的驼铃声",
"一位面目狰狞、浑身是血的中年男子，手拿一柄滴血的大刀，眼
中盈满了泪水，在朝着天空狂笑",
"一片巨大的宅院已经陷入火海，浓烟冲天而起，火光映红了半边
天，不远处的山坡上有一位满脸刀疤的男子怔怔的望着这里",
"清晨的薄雾里是一个幽静的小花园，美丽的花朵上挂着点点露珠，
偶尔一滴落下破碎开，映出七彩光亮",
});

int main(object me, string arg)
{
	int sen_cost, mana_gain;

	if( me->is_fighting() ) return notify_fail("战斗中无法静心冥思。\n");

	if( !arg || !sscanf(arg, "%d", sen_cost) )
		return notify_fail("你要花多少精神冥思？\n");

	if( sen_cost < 10 )
		return notify_fail("你最少要花 10 点「神」才能冥思。\n");

	if( (int)me->query("sen") < sen_cost )
		return notify_fail("你现在精神太差了，进行冥思将会迷失，永远醒不过来！\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");

	if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
		return notify_fail("你现在身体状况太虚弱了，无法进入冥思的状态！\n");

	if( !me->query_skill("spells",1) )
		return notify_fail("你盘膝而坐，静坐冥思了一会儿。\n大概由于没有学习过「基本咒术」，你只觉的脑子里一片空白。\n");

	mana_gain = sen_cost * ((int)me->query_skill("spells")
		+ (int)me->query("con") ) / 300;

	if(mana_gain < 1)
		mana_gain = 1;

	me->receive_damage("sen", sen_cost);
	message_vision("$N盘膝坐下，慢慢的闭上双眼开始冥思。。。。。。\n",me);

	me->start_busy(5);
	call_out("continue_mingsi",2,me,mana_gain);

	return 1;
}

private void continue_mingsi(object me,int gain)
{
	if(!objectp(me))
		return;

	write(sprintf("\n你仿佛看到%s。\n\n",m_msg[random(sizeof(m_msg))]));
	call_out("quit_mingsi",2,me,gain);
}

private void quit_mingsi(object me,int gain)
{
	if(!objectp(me))
		return;

	seteuid(getuid());

	write("你从冥思中清醒了过来，缓缓睁开眼，周围的景物渐渐的清晰了。\n");
	tell_room(environment(me),me->name()+"从冥思中清醒了过来，长抒了一口气，缓缓睁开眼。\n",({me}));

	me->add("mana", gain );

	if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
		if( (int)me->query("max_mana") >= (int)me->query_skill("spells", 1) * 10) {
			write("当你的法力增加的瞬间你忽然觉得脑中一片混乱，似乎魔力的提升已经到了瓶颈。\n");
		} else {
			write(HIC"你觉得体内一种力量在增强，你的『法力』提高了。\n"NOR);
			me->add("max_mana", 1);
		}
		me->set("mana", me->query("max_mana"));
	}
	me->stop_busy();
}

int help(object me)
{
        write(@HELP
指令格式 : meditate [<耗费「神」的量，预设值 30>]
 
静坐冥思，将游离的精神力有效地集中凝聚成能够用来施展法术的能量
，藉以增加自己的法力。

请参考 help stat 
HELP
        );
        return 1;
}
