//Room: dangpu.c

inherit ROOM;

void create ()
{
        set ("short", "���ǵ���");
        set ("long", @LONG
���ǳ�����������һ�ҵ����ˡ�������������ƽ���ơ��ſڹ���
һ������ (paizi)��һ�����߸ߵĹ�̨���������ǰ����̨�������ƹ�
�ķ��ϰ壬�������˽�����һ˫�������۾��������´������㡣
LONG);
        set("exits", ([ /* sizeof() == 1 */
        	"north" : __DIR__"qixiang3",
        ]));
        set("item_desc", ([ /* sizeof() == 1 */
        	"paizi" : "
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˡ�
�͹ٿ��������
           ������������������������������
          ��	����(sell)		��
          ��	����(value)		��
          ��	����(buy) ��list�鿴��	��
           ������������������������������
���ֻ��ͭǮ���������ƽ���Ʊһ��ͨ�á�\n"
        ]));
        set("objects", ([ /* sizeof() == 1 */
        	__DIR__"npc/wanxi" : 1,
        ]));

        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}