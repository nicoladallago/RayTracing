#include "Layout.h"
#include "Widget.h"

API void Layout::AddWidget(const unsigned int row,
                           const unsigned int col,
                           Widget* pWidget,
                           const VAlignement vAlignement,
                           const HAlignement hAlignement) {
   Data& data = m_widgets[Point2<unsigned int>(col, row)];
   data.m_upWidget.reset(pWidget);
   data.m_vAlignement = vAlignement;
   data.m_hAlignement = hAlignement;
}


bool Layout::IsPreset(const unsigned int row, const unsigned int col) const {
   return m_widgets.contains(Point2<unsigned int>(col, row));
}


const Widget& Layout::GetWidget(const unsigned int row, const unsigned int col) const {
   return *m_widgets.at(Point2<unsigned int>(col, row)).m_upWidget.get();
}


Widget& Layout::GetWidget(const unsigned int row, const unsigned int col) {
   return *m_widgets.at(Point2<unsigned int>(col, row)).m_upWidget.get();
}


void Layout::Draw(const GraphicsHandler& handler,
                  const unsigned int /*width*/,
                  const unsigned int /*height*/) const {
   // first compute column and row dimensions
   std::map<unsigned int, unsigned int> colsDim; // [col nr][width]
   std::map<unsigned int, unsigned int> rowsDim; // [row nr][height]
   for(const auto& [position, data] : m_widgets) {
      const Widget& widget = *data.m_upWidget;
      const unsigned int col = position.GetX();
      const unsigned int row = position.GetY();

      colsDim[col] = std::max(colsDim[col], widget.GetWidth());
      rowsDim[row] = std::max(rowsDim[row], widget.GetHeight());
   }

   // convert to X coordinates
   std::vector<unsigned int> startX(colsDim.size(), m_borderMargin);
   for(unsigned int col = 0; col < colsDim.size(); ++col) {
      for(unsigned int i = 0; i < col; ++i) {
         startX[col] += (colsDim.at(i) + 2 * m_innerMargin);
      }
   }

   // convert to Y coordinates
   std::vector<unsigned int> startY(rowsDim.size(), m_borderMargin);
   for(unsigned int row = 0; row < rowsDim.size(); ++row) {
      for(unsigned int i = 0; i < row; ++i) {
         startY[row] += (rowsDim.at(i) + 2 * m_innerMargin);
      }
   }

   // then plot
   for(const auto& [position, data] : m_widgets) {
      const Widget& widget = *data.m_upWidget;
      const unsigned int col = position.GetX();
      const unsigned int row = position.GetY();

      // TODO use aignement flags
      unsigned int x = startX.at(col);
      unsigned int y = startY.at(row);
      widget.Draw(handler, x, y);
   }
}